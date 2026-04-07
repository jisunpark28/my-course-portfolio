const CHARACTER_CONFIG = {
    priest: {
        frontImage: "assets/priest_front.png",
        backImage: "assets/priest_back.png",
        welcomeText: "Father: Peace be with you! Let's walk through the center door.",
    },
    nun: {
        frontImage: "assets/nun_front.png",
        backImage: "assets/nun_back.png",
        welcomeText: "Sister: Let us pray together. We'll enter through the center door now.",
    },
};

const APP_STATE = {
    isTransitioning: false,
    selectedCharacter: null,
    threeWorld: null,
    threeLoadPromise: null,
    hudBound: false,
};

const THREE_CDN_FALLBACKS = [
    "vendor/three.min.js",
    "https://cdn.jsdelivr.net/npm/three@0.165.0/build/three.min.js",
    "https://cdnjs.cloudflare.com/ajax/libs/three.js/r165/three.min.js",
];

const GESTURE_NARRATION = {
    idle: "🙂 The celebrant stands ready in reverent stillness.",
    point: "👉 The celebrant points to the Gospel and teaches the assembly.",
    hold: "📖 The gifts are held carefully in preparation for the offertory.",
    lift: "🙌 The gifts are raised high in offering to God.",
    pray: "🙏 Hands are joined in prayerful focus and silence.",
    ourFather: "👐 Arms open gently while praying the Lord's Prayer together.",
    signCross: "✝️ In the name of the Father, and of the Son, and of the Holy Spirit.",
};

const MASS_FLOW_STEPS = [
    {
        gesture: "signCross",
        title: "Entrance Rites",
        text: "✝️ The Mass begins with the Sign of the Cross and liturgical greeting.",
    },
    {
        gesture: "pray",
        title: "Penitential Act",
        text: "🙏 The assembly asks for mercy and prepares hearts for worship.",
    },
    {
        gesture: "point",
        title: "Liturgy of the Word",
        text: "📖 The Scriptures are proclaimed, and the Gospel is explained in the homily.",
    },
    {
        gesture: "hold",
        title: "Preparation of the Gifts",
        text: "🍞🍷 Bread and wine are presented and prepared at the altar.",
    },
    {
        gesture: "lift",
        title: "Eucharistic Prayer",
        text: "✨ The gifts are offered as the Church gives thanks and praise to God.",
    },
    {
        gesture: "ourFather",
        title: "Communion Rite",
        text: "👐 The faithful pray the Lord's Prayer and prepare for Communion.",
    },
    {
        gesture: "pray",
        title: "Concluding Rite",
        text: "🔔 The people are blessed and sent forth to live the Gospel.",
    },
];

function loadThreeFromUrl(url) {
    return new Promise((resolve, reject) => {
        const script = document.createElement("script");
        script.src = url;
        script.async = true;
        script.crossOrigin = "anonymous";
        script.dataset.threeFallback = url;
        script.onload = () => resolve(Boolean(window.THREE));
        script.onerror = () => reject(new Error(`Failed loading ${url}`));
        document.head.appendChild(script);
    });
}

async function ensureThreeLoaded() {
    if (window.THREE) {
        return true;
    }

    if (!APP_STATE.threeLoadPromise) {
        APP_STATE.threeLoadPromise = (async () => {
            for (const url of THREE_CDN_FALLBACKS) {
                try {
                    const loaded = await loadThreeFromUrl(url);
                    if (loaded && window.THREE) {
                        return true;
                    }
                } catch (error) {
                    console.warn("Three.js fallback failed:", error);
                }
            }
            return false;
        })();
    }

    const loaded = await APP_STATE.threeLoadPromise;
    if (!loaded) {
        APP_STATE.threeLoadPromise = null;
    }
    return loaded;
}

function setDialogue(text) {
    const dialogueBox = document.getElementById("dialogue-box");
    if (dialogueBox) {
        dialogueBox.textContent = text;
    }
}

function setLiturgySubtitle(text) {
    const subtitle = document.getElementById("liturgy-subtitle");
    if (subtitle) {
        subtitle.textContent = text;
    }
}

function setLiturgyHudVisible(isVisible) {
    const hud = document.getElementById("liturgy-hud");
    if (!hud) {
        return;
    }
    hud.classList.toggle("is-active", isVisible);
    hud.setAttribute("aria-hidden", isVisible ? "false" : "true");
}

function setHudButtonsState(currentGesture, massActive) {
    const hud = document.getElementById("liturgy-hud");
    if (!hud) {
        return;
    }

    hud.querySelectorAll(".control-btn[data-gesture]").forEach((button) => {
        button.classList.toggle("is-active", button.dataset.gesture === currentGesture);
    });

    const massButton = hud.querySelector(".control-btn[data-command='mass-toggle']");
    if (massButton) {
        massButton.classList.toggle("is-active", Boolean(massActive));
        const label = massButton.querySelector(".control-label");
        if (label) {
            label.textContent = massActive ? "Stop Mass" : "Start Mass";
        }
    }
}

function bindHudControls() {
    if (APP_STATE.hudBound) {
        return;
    }
    const hud = document.getElementById("liturgy-hud");
    if (!hud) {
        return;
    }

    hud.addEventListener("click", (event) => {
        const button = event.target.closest(".control-btn[data-command]");
        if (!button || !APP_STATE.threeWorld) {
            return;
        }
        const command = button.dataset.command;
        const world = APP_STATE.threeWorld;

        if (command === "gesture-idle") world.triggerGesture("idle");
        else if (command === "gesture-point") world.triggerGesture("point");
        else if (command === "gesture-hold") world.triggerGesture("hold");
        else if (command === "gesture-lift") world.triggerGesture("lift");
        else if (command === "gesture-pray") world.triggerGesture("pray");
        else if (command === "gesture-ourfather") world.triggerGesture("ourFather");
        else if (command === "gesture-signcross") world.triggerGesture("signCross");
        else if (command === "mass-toggle") world.toggleMassSequence();
        else if (command === "move-left") {
            world.nudgeMove(-1, 0);
            setLiturgySubtitle("⬅️ Stepped left.");
        } else if (command === "move-right") {
            world.nudgeMove(1, 0);
            setLiturgySubtitle("➡️ Stepped right.");
        } else if (command === "move-forward") {
            world.nudgeMove(0, -1);
            setLiturgySubtitle("⬆️ Moved toward the altar.");
        } else if (command === "move-back") {
            world.nudgeMove(0, 1);
            setLiturgySubtitle("⬇️ Moved toward the nave.");
        } else if (command === "jump") {
            world.triggerJump();
            setLiturgySubtitle("⤴️ Small jump.");
        }
    });

    APP_STATE.hudBound = true;
}

function parsePercent(value, fallback) {
    const numeric = Number.parseFloat(value);
    return Number.isFinite(numeric) ? numeric : fallback;
}

function getDoorAnchor() {
    const sceneEl = document.getElementById("church-scene");
    const rect = sceneEl.getBoundingClientRect();
    const style = getComputedStyle(sceneEl);

    const doorXPercent = parsePercent(style.getPropertyValue("--door-x"), 50);
    const doorYPercent = parsePercent(style.getPropertyValue("--door-y"), 73);

    return {
        x: rect.left + (rect.width * doorXPercent) / 100,
        y: rect.top + (rect.height * doorYPercent) / 100,
    };
}

function setZoomOriginFromDoor() {
    const entryScreen = document.getElementById("entry-screen");
    const door = getDoorAnchor();
    const xPercent = (door.x / window.innerWidth) * 100;
    const yPercent = (door.y / window.innerHeight) * 100;
    entryScreen.style.setProperty("--zoom-x", `${xPercent}%`);
    entryScreen.style.setProperty("--zoom-y", `${yPercent}%`);
    return { xPercent, yPercent };
}

function animateDoorZoomTransition() {
    return new Promise((resolve) => {
        const entryScreen = document.getElementById("entry-screen");
        const flash = document.getElementById("entry-flash");
        const { xPercent, yPercent } = setZoomOriginFromDoor();

        flash.style.setProperty("--zoom-x", `${xPercent}%`);
        flash.style.setProperty("--zoom-y", `${yPercent}%`);
        entryScreen.classList.add("is-entering-zoom");

        requestAnimationFrame(() => {
            flash.classList.add("is-active");
        });

        setTimeout(() => {
            flash.classList.remove("is-active");
            flash.removeAttribute("style");
            resolve();
        }, 620);
    });
}

function getCharacterElement(character) {
    return document.getElementById(`character-${character}`);
}

function lockCharacterSelection() {
    document.querySelectorAll(".character").forEach((el) => {
        el.style.pointerEvents = "none";
    });
}

function switchToBackSprite(character, characterEl) {
    const config = CHARACTER_CONFIG[character];
    const image = characterEl?.querySelector("img");
    if (config && image) {
        image.src = config.backImage;
    }
}

function animateCharacterEntry(characterEl) {
    return new Promise((resolve) => {
        const rect = characterEl.getBoundingClientRect();
        const startFoot = {
            x: rect.left + rect.width / 2,
            y: rect.bottom,
        };

        const clone = characterEl.cloneNode(true);
        clone.removeAttribute("id");
        clone.style.position = "fixed";
        clone.style.left = `${startFoot.x}px`;
        clone.style.top = `${startFoot.y}px`;
        clone.style.width = `${rect.width}px`;
        clone.style.height = `${rect.height}px`;
        clone.style.margin = "0";
        clone.style.zIndex = "99";
        clone.style.pointerEvents = "none";
        clone.style.transformOrigin = "center bottom";
        clone.style.transform = "translate(-50%, -100%) scale(1)";
        clone.style.willChange = "transform, opacity, left, top";

        document.body.appendChild(clone);
        characterEl.style.opacity = "0";
        characterEl.classList.add("is-entering");

        const duration = 1100;
        const easeOut = (t) => 1 - Math.pow(1 - t, 3);
        const easeIn = (t) => t * t;
        const startedAt = performance.now();

        const step = (now) => {
            const elapsed = now - startedAt;
            const progress = Math.min(elapsed / duration, 1);
            const movementT = easeOut(progress);
            const fadeT = easeIn(progress);
            const door = getDoorAnchor();

            const x = startFoot.x + (door.x - startFoot.x) * movementT;
            const y = startFoot.y + (door.y - startFoot.y) * movementT;
            const scale = 1 - 0.93 * easeIn(progress);

            clone.style.left = `${x}px`;
            clone.style.top = `${y}px`;
            clone.style.opacity = `${1 - fadeT}`;
            clone.style.transform = `translate(-50%, -100%) scale(${scale})`;

            if (progress < 1) {
                requestAnimationFrame(step);
                return;
            }

            clone.remove();
            resolve();
        };

        requestAnimationFrame(step);
    });
}

function addDays(date, days) {
    const next = new Date(date);
    next.setDate(next.getDate() + days);
    return next;
}

function startOfDay(date) {
    return new Date(date.getFullYear(), date.getMonth(), date.getDate());
}

function calculateEasterSunday(year) {
    const a = year % 19;
    const b = Math.floor(year / 100);
    const c = year % 100;
    const d = Math.floor(b / 4);
    const e = b % 4;
    const f = Math.floor((b + 8) / 25);
    const g = Math.floor((b - f + 1) / 3);
    const h = (19 * a + b - d - g + 15) % 30;
    const i = Math.floor(c / 4);
    const k = c % 4;
    const l = (32 + 2 * e + 2 * i - h - k) % 7;
    const m = Math.floor((a + 11 * h + 22 * l) / 451);
    const month = Math.floor((h + l - 7 * m + 114) / 31);
    const day = ((h + l - 7 * m + 114) % 31) + 1;
    return new Date(year, month - 1, day);
}

function getAdventStart(year) {
    const dec3 = new Date(year, 11, 3);
    const sundayOffset = dec3.getDay();
    const adventStart = new Date(dec3);
    adventStart.setDate(dec3.getDate() - sundayOffset);
    return adventStart;
}

function getLiturgicalSeason(inputDate = new Date()) {
    const date = startOfDay(inputDate);
    const year = date.getFullYear();

    const easterSunday = calculateEasterSunday(year);
    const ashWednesday = addDays(easterSunday, -46);
    const holySaturday = addDays(easterSunday, -1);
    const pentecost = addDays(easterSunday, 49);

    const adventStart = getAdventStart(year);
    const christmasDay = new Date(year, 11, 25);
    const christmasEnd = new Date(year + 1, 0, 12);
    const christmasStartPreviousYear = new Date(year - 1, 11, 25);
    const christmasEndCurrentYear = new Date(year, 0, 12);

    if ((date >= christmasDay && date <= christmasEnd) || (date >= christmasStartPreviousYear && date <= christmasEndCurrentYear)) {
        return { season: "Christmas", colorName: "White", colorHex: 0xf7f4e8 };
    }
    if (date >= adventStart && date < christmasDay) {
        return { season: "Advent", colorName: "Purple", colorHex: 0x7d5db0 };
    }
    if (date >= ashWednesday && date <= holySaturday) {
        return { season: "Lent", colorName: "Purple", colorHex: 0x6f4fa8 };
    }
    if (date >= easterSunday && date <= pentecost) {
        return { season: "Easter", colorName: "White", colorHex: 0xffffff };
    }

    return { season: "Ordinary Time", colorName: "Green", colorHex: 0x4d9c5a };
}

function createVoxelChurch(container) {
    if (typeof THREE === "undefined") {
        throw new Error("Three.js is not loaded.");
    }

    const scene = new THREE.Scene();
    scene.background = new THREE.Color(0xf5f5dc);
    scene.fog = new THREE.Fog(0xf5f5dc, 20, 56);

    const camera = new THREE.PerspectiveCamera(54, window.innerWidth / window.innerHeight, 0.1, 100);

    const renderer = new THREE.WebGLRenderer({ antialias: true });
    renderer.setPixelRatio(Math.min(window.devicePixelRatio || 1, 2));
    renderer.setSize(window.innerWidth, window.innerHeight);
    renderer.outputColorSpace = THREE.SRGBColorSpace;
    renderer.shadowMap.enabled = true;
    container.innerHTML = "";
    container.appendChild(renderer.domElement);

    const ambientLight = new THREE.AmbientLight(0xfff0d0, 1.15);
    const hemiLight = new THREE.HemisphereLight(0xffefcf, 0xc6b38d, 0.7);
    const sunLight = new THREE.DirectionalLight(0xffdfab, 0.9);
    sunLight.position.set(10, 14, 5);
    sunLight.castShadow = true;

    const altarGlow = new THREE.PointLight(0xfff1cc, 0.8, 30, 2);
    altarGlow.position.set(0, 7.5, -12);

    scene.add(ambientLight, hemiLight, sunLight, altarGlow);

    const materials = {
        floor: new THREE.MeshLambertMaterial({ color: 0xdac69f }),
        floorPath: new THREE.MeshLambertMaterial({ color: 0xe9d8b5 }),
        wood: new THREE.MeshLambertMaterial({ color: 0xb48960 }),
        darkWood: new THREE.MeshLambertMaterial({ color: 0x8d6541 }),
        wall: new THREE.MeshLambertMaterial({ color: 0xf2e6cb }),
        roof: new THREE.MeshLambertMaterial({ color: 0xe5d1a6 }),
        altarCloth: new THREE.MeshLambertMaterial({ color: 0x4d9c5a }),
        stainedGlassBlue: new THREE.MeshLambertMaterial({ color: 0x8cc2e8 }),
        stainedGlassGold: new THREE.MeshLambertMaterial({ color: 0xe8d17c }),
        candleWax: new THREE.MeshLambertMaterial({ color: 0xf8f1dc }),
        candleFlame: new THREE.MeshBasicMaterial({ color: 0xffcf73 }),
        corpusSkin: new THREE.MeshLambertMaterial({ color: 0xf1d0b1 }),
        corpusCloth: new THREE.MeshLambertMaterial({ color: 0xf2eee4 }),
    };

    const root = new THREE.Group();
    scene.add(root);

    const floor = new THREE.Mesh(new THREE.BoxGeometry(34, 1, 36), materials.floor);
    floor.position.set(0, -0.5, 0);
    floor.receiveShadow = true;
    root.add(floor);

    const centralPath = new THREE.Mesh(new THREE.BoxGeometry(4.3, 0.2, 29), materials.floorPath);
    centralPath.position.set(0, 0.11, 0.5);
    root.add(centralPath);

    const backWall = new THREE.Mesh(new THREE.BoxGeometry(34, 12, 1), materials.wall);
    backWall.position.set(0, 6, -17.5);
    const leftWall = new THREE.Mesh(new THREE.BoxGeometry(1, 12, 36), materials.wall);
    leftWall.position.set(-16.5, 6, 0);
    const rightWall = new THREE.Mesh(new THREE.BoxGeometry(1, 12, 36), materials.wall);
    rightWall.position.set(16.5, 6, 0);
    const ceiling = new THREE.Mesh(new THREE.BoxGeometry(34, 1, 36), materials.roof);
    ceiling.position.set(0, 12.1, 0);
    root.add(backWall, leftWall, rightWall, ceiling);

    const sanctuaryStep = new THREE.Mesh(new THREE.BoxGeometry(12, 0.8, 7), materials.wood);
    sanctuaryStep.position.set(0, 0.4, -12.4);
    root.add(sanctuaryStep);

    const altarGroup = new THREE.Group();
    altarGroup.position.set(0, 0.4, -12.2);
    root.add(altarGroup);

    const altarBase = new THREE.Mesh(new THREE.BoxGeometry(7, 2.3, 3.7), materials.wood);
    altarBase.position.y = 1.15;
    altarBase.userData.interactive = true;
    altarBase.castShadow = true;
    altarGroup.add(altarBase);

    const altarCloth = new THREE.Mesh(new THREE.BoxGeometry(7.2, 0.42, 3.9), materials.altarCloth);
    altarCloth.position.y = 2.52;
    altarCloth.userData.interactive = true;
    altarCloth.castShadow = true;
    altarGroup.add(altarCloth);

    const crossStand = new THREE.Mesh(new THREE.BoxGeometry(0.8, 5.2, 0.8), materials.darkWood);
    crossStand.position.set(0, 6.1, -0.2);
    crossStand.userData.interactive = true;
    crossStand.castShadow = true;
    altarGroup.add(crossStand);

    const crossBeam = new THREE.Mesh(new THREE.BoxGeometry(3.2, 0.8, 0.8), materials.darkWood);
    crossBeam.position.set(0, 7.3, -0.2);
    crossBeam.userData.interactive = true;
    crossBeam.castShadow = true;
    altarGroup.add(crossBeam);

    const corpusGroup = new THREE.Group();
    corpusGroup.position.set(0, 0, 0);
    altarGroup.add(corpusGroup);

    const corpusTorso = new THREE.Mesh(new THREE.BoxGeometry(0.62, 1.9, 0.3), materials.corpusSkin);
    corpusTorso.position.set(0, 6.2, 0.25);
    corpusTorso.castShadow = true;
    corpusTorso.name = "corpus-torso";
    corpusGroup.add(corpusTorso);

    const corpusHead = new THREE.Mesh(new THREE.BoxGeometry(0.5, 0.52, 0.38), materials.corpusSkin);
    corpusHead.position.set(0, 7.42, 0.25);
    corpusHead.castShadow = true;
    corpusHead.name = "corpus-head";
    corpusGroup.add(corpusHead);

    const corpusArms = new THREE.Mesh(new THREE.BoxGeometry(2.35, 0.26, 0.28), materials.corpusSkin);
    corpusArms.position.set(0, 7.15, 0.25);
    corpusArms.castShadow = true;
    corpusArms.name = "corpus-arms";
    corpusGroup.add(corpusArms);

    const corpusLeftLeg = new THREE.Mesh(new THREE.BoxGeometry(0.24, 0.95, 0.24), materials.corpusSkin);
    corpusLeftLeg.position.set(-0.12, 4.78, 0.24);
    corpusLeftLeg.castShadow = true;
    corpusLeftLeg.name = "corpus-left-leg";
    corpusGroup.add(corpusLeftLeg);

    const corpusRightLeg = new THREE.Mesh(new THREE.BoxGeometry(0.24, 0.95, 0.24), materials.corpusSkin);
    corpusRightLeg.position.set(0.12, 4.78, 0.24);
    corpusRightLeg.castShadow = true;
    corpusRightLeg.name = "corpus-right-leg";
    corpusGroup.add(corpusRightLeg);

    const corpusCloth = new THREE.Mesh(new THREE.BoxGeometry(0.78, 0.42, 0.3), materials.corpusCloth);
    corpusCloth.position.set(0, 5.38, 0.26);
    corpusCloth.castShadow = true;
    corpusCloth.name = "corpus-cloth";
    corpusGroup.add(corpusCloth);

    const candleL = new THREE.Mesh(new THREE.BoxGeometry(0.35, 1.2, 0.35), materials.candleWax);
    candleL.position.set(-2.8, 3.2, 0.7);
    candleL.userData.interactive = true;
    altarGroup.add(candleL);

    const candleR = new THREE.Mesh(new THREE.BoxGeometry(0.35, 1.2, 0.35), materials.candleWax);
    candleR.position.set(2.8, 3.2, 0.7);
    candleR.userData.interactive = true;
    altarGroup.add(candleR);

    const flameL = new THREE.Mesh(new THREE.BoxGeometry(0.22, 0.28, 0.22), materials.candleFlame);
    flameL.position.set(-2.8, 4.0, 0.7);
    altarGroup.add(flameL);

    const flameR = new THREE.Mesh(new THREE.BoxGeometry(0.22, 0.28, 0.22), materials.candleFlame);
    flameR.position.set(2.8, 4.0, 0.7);
    altarGroup.add(flameR);

    function addWindowSet(x, y, z, rotationY) {
        const frame = new THREE.Mesh(new THREE.BoxGeometry(0.9, 2.8, 2.2), materials.darkWood);
        frame.position.set(x, y, z);
        frame.rotation.y = rotationY;
        const glassTop = new THREE.Mesh(new THREE.BoxGeometry(0.25, 2.3, 1.7), materials.stainedGlassBlue);
        glassTop.position.set(x, y + 0.15, z);
        glassTop.rotation.y = rotationY;
        const glassAccent = new THREE.Mesh(new THREE.BoxGeometry(0.3, 0.4, 1.7), materials.stainedGlassGold);
        glassAccent.position.set(x, y - 0.8, z);
        glassAccent.rotation.y = rotationY;
        root.add(frame, glassTop, glassAccent);
    }

    addWindowSet(-16.0, 5.1, -9.8, 0);
    addWindowSet(-16.0, 5.1, -2.2, 0);
    addWindowSet(-16.0, 5.1, 5.4, 0);
    addWindowSet(16.0, 5.1, -9.8, 0);
    addWindowSet(16.0, 5.1, -2.2, 0);
    addWindowSet(16.0, 5.1, 5.4, 0);

    for (let row = 0; row < 4; row += 1) {
        for (let side = -1; side <= 1; side += 2) {
            const pew = new THREE.Mesh(new THREE.BoxGeometry(5.8, 1.0, 1.45), materials.wood);
            pew.position.set(side * 7.2, 0.55, row * 3.3 - 2.6);
            pew.castShadow = true;
            pew.receiveShadow = true;
            root.add(pew);

            const back = new THREE.Mesh(new THREE.BoxGeometry(5.8, 1.2, 0.35), materials.darkWood);
            back.position.set(side * 7.2, 1.25, row * 3.3 - 3.1);
            root.add(back);
        }
    }

    const selected = CHARACTER_CONFIG[APP_STATE.selectedCharacter] || CHARACTER_CONFIG.nun;
    const isPriest = APP_STATE.selectedCharacter === "priest";

    const playerRig = new THREE.Group();
    playerRig.position.set(0, 0, 10.8);
    root.add(playerRig);

    const robeMaterial = new THREE.MeshLambertMaterial({ color: isPriest ? 0x252529 : 0x1c1c22 });
    const skinMaterial = new THREE.MeshLambertMaterial({ color: 0xf3d8bd });
    const accentMaterial = new THREE.MeshLambertMaterial({ color: isPriest ? 0xd9d9df : 0xe3e3ea });

    const torso = new THREE.Mesh(new THREE.BoxGeometry(1.2, 1.6, 0.6), robeMaterial);
    torso.position.set(0, 1.35, -0.2);
    playerRig.add(torso);

    const head = new THREE.Mesh(new THREE.BoxGeometry(0.78, 0.78, 0.68), skinMaterial);
    head.position.set(0, 2.6, -0.18);
    playerRig.add(head);

    const collar = new THREE.Mesh(new THREE.BoxGeometry(0.52, 0.18, 0.62), accentMaterial);
    collar.position.set(0, 2.06, 0.02);
    playerRig.add(collar);

    const playerTexture = new THREE.TextureLoader().load(selected.frontImage);
    if ("colorSpace" in playerTexture) {
        playerTexture.colorSpace = THREE.SRGBColorSpace;
    }
    playerTexture.magFilter = THREE.NearestFilter;

    const playerSprite = new THREE.Sprite(
        new THREE.SpriteMaterial({
            map: playerTexture,
            transparent: true,
            alphaTest: 0.18,
        }),
    );
    playerSprite.scale.set(2.5, 3.0, 1);
    playerSprite.position.set(0, 1.55, 0.05);
    playerRig.add(playerSprite);

    const itemMaterial = new THREE.MeshLambertMaterial({ color: 0xc6a278 });
    const liturgyItem = new THREE.Mesh(new THREE.BoxGeometry(0.52, 0.64, 0.26), itemMaterial);
    liturgyItem.visible = false;
    playerRig.add(liturgyItem);

    function createArm(side) {
        const shoulder = new THREE.Object3D();
        shoulder.position.set(side * 0.82, 2.16, -0.05);

        const upper = new THREE.Mesh(new THREE.BoxGeometry(0.24, 0.92, 0.24), robeMaterial);
        upper.position.y = -0.46;
        shoulder.add(upper);

        const elbow = new THREE.Object3D();
        elbow.position.y = -0.92;
        shoulder.add(elbow);

        const lower = new THREE.Mesh(new THREE.BoxGeometry(0.21, 0.84, 0.21), robeMaterial);
        lower.position.y = -0.42;
        elbow.add(lower);

        const hand = new THREE.Mesh(new THREE.BoxGeometry(0.19, 0.19, 0.19), skinMaterial);
        hand.position.y = -0.86;
        elbow.add(hand);

        playerRig.add(shoulder);
        return { shoulder, elbow };
    }

    const leftArm = createArm(-1);
    const rightArm = createArm(1);

    const armPoseCurrent = {
        left: { ux: 0, uy: 0, uz: 0, lx: 0, ly: 0, lz: 0 },
        right: { ux: 0, uy: 0, uz: 0, lx: 0, ly: 0, lz: 0 },
    };
    const armPoseTarget = {
        left: { ux: 0, uy: 0, uz: 0, lx: 0, ly: 0, lz: 0 },
        right: { ux: 0, uy: 0, uz: 0, lx: 0, ly: 0, lz: 0 },
    };

    function setArmTargets(left, right) {
        Object.assign(armPoseTarget.left, left);
        Object.assign(armPoseTarget.right, right);
    }

    function setGesturePose(gesture) {
        switch (gesture) {
            case "point":
                setArmTargets(
                    { ux: -0.4, uy: 0.15, uz: 0.2, lx: -0.28, ly: 0, lz: 0 },
                    { ux: -1.35, uy: -0.2, uz: -0.32, lx: -0.18, ly: 0, lz: 0 },
                );
                break;
            case "hold":
                setArmTargets(
                    { ux: -1.0, uy: 0.18, uz: 0.44, lx: -0.52, ly: 0, lz: 0 },
                    { ux: -1.0, uy: -0.18, uz: -0.44, lx: -0.52, ly: 0, lz: 0 },
                );
                break;
            case "lift":
                setArmTargets(
                    { ux: -2.35, uy: 0.1, uz: 0.16, lx: -0.2, ly: 0, lz: 0 },
                    { ux: -2.35, uy: -0.1, uz: -0.16, lx: -0.2, ly: 0, lz: 0 },
                );
                break;
            case "pray":
                setArmTargets(
                    { ux: -1.25, uy: 0.1, uz: 0.58, lx: -0.5, ly: 0, lz: 0 },
                    { ux: -1.25, uy: -0.1, uz: -0.58, lx: -0.5, ly: 0, lz: 0 },
                );
                break;
            case "ourFather":
                setArmTargets(
                    { ux: -0.75, uy: 0.2, uz: 1.02, lx: -0.82, ly: 0, lz: 0 },
                    { ux: -0.75, uy: -0.2, uz: -1.02, lx: -0.82, ly: 0, lz: 0 },
                );
                break;
            default:
                setArmTargets(
                    { ux: -0.2, uy: 0.08, uz: 0.18, lx: -0.08, ly: 0, lz: 0 },
                    { ux: -0.2, uy: -0.08, uz: -0.18, lx: -0.08, ly: 0, lz: 0 },
                );
        }
    }

    const actionState = {
        currentGesture: "idle",
        signCrossActive: false,
        signCrossTime: 0,
        massActive: false,
        massIndex: 0,
        massTimer: 0,
        massStepDuration: 2.8,
    };
    const massSequence = MASS_FLOW_STEPS.map((step) => step.gesture);

    function narrateGesture(name, prefix = "") {
        const message = GESTURE_NARRATION[name] || GESTURE_NARRATION.idle;
        const merged = prefix ? `${prefix} ${message}` : message;
        setLiturgySubtitle(merged);
        setHudButtonsState(name, actionState.massActive);
    }

    function triggerGesture(name, prefix = "") {
        actionState.currentGesture = name;
        actionState.massTimer = actionState.massStepDuration;
        if (name === "signCross") {
            actionState.signCrossActive = true;
            actionState.signCrossTime = 0;
            setGesturePose("pray");
            narrateGesture("signCross", prefix);
            return;
        }
        actionState.signCrossActive = false;
        setGesturePose(name);
        narrateGesture(name, prefix);
    }

    function advanceMassStep() {
        const stepIndex = actionState.massIndex % MASS_FLOW_STEPS.length;
        const step = MASS_FLOW_STEPS[stepIndex];
        const next = step.gesture;
        const stepNumber = stepIndex + 1;
        const prefix = `🎼 ${step.title} (${stepNumber}/${MASS_FLOW_STEPS.length})`;
        actionState.massIndex += 1;
        triggerGesture(next, `${prefix} ${step.text}`);
    }

    function setMassMode(isActive) {
        if (isActive === actionState.massActive) {
            return;
        }
        actionState.massActive = isActive;
        if (actionState.massActive) {
            actionState.massIndex = 0;
            advanceMassStep();
            setDialogue("Mass sequence started. Press M again to stop.");
            return;
        }
        triggerGesture("idle");
        setLiturgySubtitle("⏸️ Mass sequence paused. Select any gesture manually.");
        setDialogue("Mass sequence paused.");
    }

    triggerGesture("idle");

    const playerShadow = new THREE.Mesh(
        new THREE.CircleGeometry(0.82, 16),
        new THREE.MeshBasicMaterial({
            color: 0x000000,
            transparent: true,
            opacity: 0.18,
        }),
    );
    playerShadow.rotation.x = -Math.PI / 2;
    playerShadow.position.set(playerRig.position.x, 0.02, playerRig.position.z);
    root.add(playerShadow);

    applyRoleCamera(APP_STATE.selectedCharacter, camera, playerRig);

    const keyState = new Set();
    const playerVelocity = { y: 0 };
    const playerMotion = {
        speed: 7.1,
        gravity: 18,
        jump: 8,
        onGround: true,
        jumpLatch: false,
        groundY: 0,
    };

    function attemptJump() {
        if (playerMotion.onGround && !playerMotion.jumpLatch) {
            playerVelocity.y = playerMotion.jump;
            playerMotion.onGround = false;
            playerMotion.jumpLatch = true;
        }
    }

    function nudgeMove(dx, dz) {
        const length = Math.hypot(dx, dz);
        if (length === 0) {
            return;
        }
        const nx = dx / length;
        const nz = dz / length;
        playerRig.position.x = THREE.MathUtils.clamp(playerRig.position.x + nx * 1.15, -13.8, 13.8);
        playerRig.position.z = THREE.MathUtils.clamp(playerRig.position.z + nz * 1.15, -14.6, 14.8);
    }

    function onKeyDown(event) {
        if ([
            "ArrowUp",
            "ArrowDown",
            "ArrowLeft",
            "ArrowRight",
            "Space",
            "Digit1",
            "Digit2",
            "Digit3",
            "Digit4",
            "Digit5",
            "Digit6",
            "Digit7",
            "KeyM",
        ].includes(event.code)) {
            event.preventDefault();
        }
        keyState.add(event.code);

        if (event.repeat) {
            return;
        }

        if (event.code === "Digit1") {
            if (actionState.massActive) setMassMode(false);
            triggerGesture("idle");
        } else if (event.code === "Digit2") {
            if (actionState.massActive) setMassMode(false);
            triggerGesture("point");
        } else if (event.code === "Digit3") {
            if (actionState.massActive) setMassMode(false);
            triggerGesture("hold");
        } else if (event.code === "Digit4") {
            if (actionState.massActive) setMassMode(false);
            triggerGesture("lift");
        } else if (event.code === "Digit5") {
            if (actionState.massActive) setMassMode(false);
            triggerGesture("pray");
        } else if (event.code === "Digit6") {
            if (actionState.massActive) setMassMode(false);
            triggerGesture("ourFather");
        } else if (event.code === "Digit7") {
            if (actionState.massActive) setMassMode(false);
            triggerGesture("signCross");
        } else if (event.code === "KeyM") {
            setMassMode(!actionState.massActive);
        }
    }

    function onKeyUp(event) {
        keyState.delete(event.code);
    }

    window.addEventListener("keydown", onKeyDown, { passive: false });
    window.addEventListener("keyup", onKeyUp);

    function applyPoseToArm(arm, pose) {
        arm.shoulder.rotation.set(pose.ux, pose.uy, pose.uz);
        arm.elbow.rotation.set(pose.lx, pose.ly, pose.lz);
    }

    function updateSignOfCross(dt) {
        if (!actionState.signCrossActive) {
            return;
        }

        actionState.signCrossTime += dt;
        const normalized = Math.min(actionState.signCrossTime / 2.2, 1);
        const phase = normalized * 4;

        if (phase < 1) {
            setArmTargets(
                { ux: -0.95, uy: 0.08, uz: 0.42, lx: -0.42, ly: 0, lz: 0 },
                { ux: -2.05, uy: -0.12, uz: -0.06, lx: -0.6, ly: 0, lz: 0 },
            );
        } else if (phase < 2) {
            setArmTargets(
                { ux: -0.95, uy: 0.08, uz: 0.42, lx: -0.42, ly: 0, lz: 0 },
                { ux: -1.2, uy: 0, uz: 0.08, lx: -0.2, ly: 0, lz: 0 },
            );
        } else if (phase < 3) {
            setArmTargets(
                { ux: -0.95, uy: 0.08, uz: 0.42, lx: -0.42, ly: 0, lz: 0 },
                { ux: -1.0, uy: 0.55, uz: 0.26, lx: -0.12, ly: 0, lz: 0 },
            );
        } else {
            setArmTargets(
                { ux: -0.95, uy: 0.08, uz: 0.42, lx: -0.42, ly: 0, lz: 0 },
                { ux: -1.0, uy: -0.55, uz: -0.26, lx: -0.12, ly: 0, lz: 0 },
            );
        }

        if (normalized >= 1) {
            actionState.signCrossActive = false;
            if (actionState.currentGesture === "signCross") {
                actionState.currentGesture = "pray";
                setGesturePose("pray");
                narrateGesture("pray", "✝️ After completing the Sign of the Cross,");
            }
        }
    }

    function updateMassSequence(dt) {
        if (!actionState.massActive) {
            return;
        }
        actionState.massTimer -= dt;
        if (actionState.massTimer <= 0) {
            advanceMassStep();
        }
    }

    function updateLiturgyItem() {
        const gesture = actionState.currentGesture;
        if (gesture === "hold") {
            liturgyItem.visible = true;
            liturgyItem.position.set(0, 1.95, 0.45);
            liturgyItem.rotation.set(0, 0, 0);
        } else if (gesture === "lift") {
            liturgyItem.visible = true;
            liturgyItem.position.set(0, 3.55, 0.2);
            liturgyItem.rotation.set(0, 0.35, 0);
        } else {
            liturgyItem.visible = false;
        }
    }

    function updateArmPoseSmoothing(dt) {
        const smoothing = Math.min(dt * 9, 1);
        for (const side of ["left", "right"]) {
            for (const key of ["ux", "uy", "uz", "lx", "ly", "lz"]) {
                armPoseCurrent[side][key] += (armPoseTarget[side][key] - armPoseCurrent[side][key]) * smoothing;
            }
        }
        applyPoseToArm(leftArm, armPoseCurrent.left);
        applyPoseToArm(rightArm, armPoseCurrent.right);
    }

    const raycaster = new THREE.Raycaster();
    const pointer = new THREE.Vector2();
    const interactiveMeshes = [altarBase, altarCloth, crossStand, crossBeam, candleL, candleR];
    const jumpTweens = [];
    const sparkleParticles = [];

    function triggerJump(mesh) {
        jumpTweens.push({
            mesh,
            baseY: mesh.position.y,
            elapsed: 0,
            duration: 0.45,
            amplitude: 0.28,
        });
    }

    function spawnSparkles(worldPoint, colorHex) {
        for (let i = 0; i < 12; i += 1) {
            const spark = new THREE.Mesh(
                new THREE.BoxGeometry(0.12, 0.12, 0.12),
                new THREE.MeshBasicMaterial({
                    color: colorHex,
                    transparent: true,
                    opacity: 0.92,
                }),
            );

            spark.position.copy(worldPoint);
            spark.position.y += 0.3;
            spark.userData.velocity = new THREE.Vector3(
                (Math.random() - 0.5) * 1.2,
                0.5 + Math.random() * 0.9,
                (Math.random() - 0.5) * 1.2,
            );
            spark.userData.life = 0.65 + Math.random() * 0.35;
            sparkleParticles.push(spark);
            scene.add(spark);
        }
    }

    renderer.domElement.addEventListener("pointerdown", (event) => {
        const bounds = renderer.domElement.getBoundingClientRect();
        pointer.x = ((event.clientX - bounds.left) / bounds.width) * 2 - 1;
        pointer.y = -((event.clientY - bounds.top) / bounds.height) * 2 + 1;
        raycaster.setFromCamera(pointer, camera);

        const hit = raycaster.intersectObjects(interactiveMeshes, false)[0];
        if (!hit) return;

        triggerJump(hit.object);
        spawnSparkles(hit.point, hit.object === altarCloth ? altarCloth.material.color.getHex() : 0xffe596);
    });

    const cameraOffset = new THREE.Vector3(0, 4.6, 9.2);
    const cameraLookOffset = new THREE.Vector3(0, 1.4, -4.1);
    const cameraTarget = new THREE.Vector3();
    const cameraLookTarget = new THREE.Vector3();
    const clock = new THREE.Clock();

    function animate() {
        const dt = Math.min(clock.getDelta(), 0.05);

        updateMassSequence(dt);
        updateSignOfCross(dt);
        updateArmPoseSmoothing(dt);
        updateLiturgyItem();

        const left = keyState.has("ArrowLeft") || keyState.has("KeyA");
        const right = keyState.has("ArrowRight") || keyState.has("KeyD");
        const up = keyState.has("ArrowUp") || keyState.has("KeyW");
        const down = keyState.has("ArrowDown") || keyState.has("KeyS");
        const jump = keyState.has("Space");

        let moveX = (right ? 1 : 0) - (left ? 1 : 0);
        let moveZ = (down ? 1 : 0) - (up ? 1 : 0);
        const moveLength = Math.hypot(moveX, moveZ);
        if (moveLength > 0) {
            moveX /= moveLength;
            moveZ /= moveLength;
        }

        playerRig.position.x += moveX * playerMotion.speed * dt;
        playerRig.position.z += moveZ * playerMotion.speed * dt;
        playerRig.position.x = THREE.MathUtils.clamp(playerRig.position.x, -13.8, 13.8);
        playerRig.position.z = THREE.MathUtils.clamp(playerRig.position.z, -14.6, 14.8);

        if (jump) {
            attemptJump();
        }
        if (!jump) {
            playerMotion.jumpLatch = false;
        }

        if (!playerMotion.onGround) {
            playerVelocity.y -= playerMotion.gravity * dt;
            playerRig.position.y += playerVelocity.y * dt;
            if (playerRig.position.y <= playerMotion.groundY) {
                playerRig.position.y = playerMotion.groundY;
                playerVelocity.y = 0;
                playerMotion.onGround = true;
            }
        }

        playerShadow.position.x = playerRig.position.x;
        playerShadow.position.z = playerRig.position.z;
        playerShadow.material.opacity = 0.2 - Math.min((playerRig.position.y - playerMotion.groundY) * 0.05, 0.1);

        for (let i = jumpTweens.length - 1; i >= 0; i -= 1) {
            const tween = jumpTweens[i];
            tween.elapsed += dt;
            const t = Math.min(tween.elapsed / tween.duration, 1);
            const bump = Math.sin(t * Math.PI) * tween.amplitude;
            tween.mesh.position.y = tween.baseY + bump;
            if (t >= 1) {
                tween.mesh.position.y = tween.baseY;
                jumpTweens.splice(i, 1);
            }
        }

        for (let i = sparkleParticles.length - 1; i >= 0; i -= 1) {
            const spark = sparkleParticles[i];
            spark.userData.life -= dt;
            if (spark.userData.life <= 0) {
                spark.material.dispose();
                spark.geometry.dispose();
                scene.remove(spark);
                sparkleParticles.splice(i, 1);
                continue;
            }

            spark.position.addScaledVector(spark.userData.velocity, dt);
            spark.userData.velocity.y -= 1.45 * dt;
            spark.material.opacity = Math.max(spark.userData.life, 0);
        }

        flameL.scale.y = 0.85 + Math.sin(performance.now() * 0.013) * 0.08;
        flameR.scale.y = 0.85 + Math.sin(performance.now() * 0.012 + 0.8) * 0.08;

        cameraTarget.copy(playerRig.position).add(cameraOffset);
        camera.position.lerp(cameraTarget, 0.1);
        cameraLookTarget.copy(playerRig.position).add(cameraLookOffset);
        camera.lookAt(cameraLookTarget);

        renderer.render(scene, camera);
        requestAnimationFrame(animate);
    }

    animate();

    function onResize() {
        camera.aspect = window.innerWidth / window.innerHeight;
        camera.updateProjectionMatrix();
        renderer.setSize(window.innerWidth, window.innerHeight);
    }

    window.addEventListener("resize", onResize);

    return {
        scene,
        camera,
        renderer,
        altarCloth,
        crucifixGroup: corpusGroup,
        playerRig,
        triggerGesture: (name) => {
            if (actionState.massActive) setMassMode(false);
            triggerGesture(name);
        },
        toggleMassSequence: () => setMassMode(!actionState.massActive),
        nudgeMove,
        triggerJump: () => {
            playerMotion.jumpLatch = false;
            attemptJump();
        },
        getCurrentGesture: () => actionState.currentGesture,
        isMassActive: () => actionState.massActive,
    };
}

function applyRoleCamera(role, camera, playerRig = null) {
    const anchorX = playerRig ? playerRig.position.x : 0;
    const anchorY = playerRig ? playerRig.position.y : 0;
    const anchorZ = playerRig ? playerRig.position.z : 10.8;
    camera.position.set(anchorX, anchorY + 4.6, anchorZ + 9.2);
    camera.lookAt(anchorX, anchorY + 1.4, anchorZ - 4.1);
}

function resetEntryAfterFailure(message) {
    const entryScreen = document.getElementById("entry-screen");
    const flash = document.getElementById("entry-flash");
    const threeContainer = document.getElementById("three-container");
    const selectedEl = getCharacterElement(APP_STATE.selectedCharacter);
    const selectedConfig = CHARACTER_CONFIG[APP_STATE.selectedCharacter];

    if (selectedEl && selectedConfig) {
        selectedEl.style.opacity = "1";
        selectedEl.classList.remove("is-entering");
        const image = selectedEl.querySelector("img");
        if (image) {
            image.src = selectedConfig.frontImage;
        }
    }

    document.querySelectorAll(".character").forEach((el) => {
        el.style.pointerEvents = "";
        el.classList.remove("is-entering");
        if (el.style.opacity === "0") {
            el.style.opacity = "1";
        }
    });

    flash.classList.remove("is-active");
    flash.removeAttribute("style");
    threeContainer.classList.remove("is-active");
    threeContainer.setAttribute("aria-hidden", "true");
    setLiturgyHudVisible(false);
    entryScreen.classList.remove("is-hidden", "is-entering-zoom");
    entryScreen.style.display = "flex";
    APP_STATE.isTransitioning = false;
    setDialogue(message);
    setLiturgySubtitle("🎵 Mass guidance subtitles will appear here.");
}

async function activateThreeScene(role) {
    const entryScreen = document.getElementById("entry-screen");
    const threeContainer = document.getElementById("three-container");
    const liturgical = getLiturgicalSeason(new Date());
    const isThreeReady = await ensureThreeLoaded();

    if (!isThreeReady || !window.THREE) {
        resetEntryAfterFailure("3D engine failed to load. Please check internet and try again.");
        return;
    }

    entryScreen.classList.add("is-hidden");
    setTimeout(() => {
        entryScreen.style.display = "none";
    }, 560);

    threeContainer.classList.add("is-active");
    threeContainer.setAttribute("aria-hidden", "false");
    bindHudControls();
    setLiturgyHudVisible(true);

    try {
        if (!APP_STATE.threeWorld) {
            APP_STATE.threeWorld = createVoxelChurch(threeContainer);
        }

        APP_STATE.threeWorld.altarCloth.material.color.setHex(liturgical.colorHex);
        APP_STATE.threeWorld.altarCloth.material.needsUpdate = true;

        applyRoleCamera(role, APP_STATE.threeWorld.camera, APP_STATE.threeWorld.playerRig);
        setHudButtonsState(APP_STATE.threeWorld.getCurrentGesture(), APP_STATE.threeWorld.isMassActive());
        setDialogue(`Today is ${liturgical.season}. Move: arrows/WASD, jump: Space, gestures: 1-7, Mass sequence: M.`);
    } catch (error) {
        console.error("Failed to initialize 3D church scene:", error);
        resetEntryAfterFailure("The church interior could not load. Please refresh and try again.");
    }
}

/**
 * Handles character interaction and transitions to the 3D church scene.
 * @param {string} character
 */
async function handleInteract(character) {
    if (APP_STATE.isTransitioning || !CHARACTER_CONFIG[character]) {
        return;
    }

    APP_STATE.isTransitioning = true;
    APP_STATE.selectedCharacter = character;

    const characterEl = getCharacterElement(character);
    if (!characterEl) {
        APP_STATE.isTransitioning = false;
        return;
    }

    lockCharacterSelection();
    switchToBackSprite(character, characterEl);
    setDialogue(CHARACTER_CONFIG[character].welcomeText);

    await animateCharacterEntry(characterEl);
    await animateDoorZoomTransition();
    await activateThreeScene(character);
}

window.handleInteract = handleInteract;
window.getLiturgicalSeason = getLiturgicalSeason;