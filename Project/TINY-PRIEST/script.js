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
    massNavBound: false,
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
        part: "1. Introductory Rites",
        partEn: "Introductory Rites",
        gesture: "idle",
        title: "Entrance Song",
        text: "🎶 The assembly gathers and the entrance procession begins.",
    },
    {
        part: "1. Introductory Rites",
        partEn: "Introductory Rites",
        gesture: "signCross",
        title: "Sign of the Cross",
        text: "✝️ The Mass begins with the Sign of the Cross and liturgical greeting.",
    },
    {
        part: "1. Introductory Rites",
        partEn: "Introductory Rites",
        gesture: "pray",
        title: "Penitential Rite",
        text: "🙏 The assembly asks for mercy and prepares hearts for worship.",
    },
    {
        part: "1. Introductory Rites",
        partEn: "Introductory Rites",
        gesture: "pray",
        title: "Kyrie",
        text: "🕯️ Lord, have mercy; Christ, have mercy.",
    },
    {
        part: "1. Introductory Rites",
        partEn: "Introductory Rites",
        gesture: "ourFather",
        title: "Gloria",
        text: "✨ Glory to God in the highest is proclaimed in praise.",
    },
    {
        part: "1. Introductory Rites",
        partEn: "Introductory Rites",
        gesture: "pray",
        title: "The Collect",
        text: "🕯️ The opening prayer gathers the intentions of the faithful.",
    },
    {
        part: "2. Liturgy of the Word",
        partEn: "Liturgy of the Word",
        gesture: "point",
        title: "1st Reading",
        text: "📖 The first reading is proclaimed from Sacred Scripture.",
    },
    {
        part: "2. Liturgy of the Word",
        partEn: "Liturgy of the Word",
        gesture: "ourFather",
        title: "Responsorial Psalm",
        text: "🎵 The psalm is prayed in response with the assembly.",
    },
    {
        part: "2. Liturgy of the Word",
        partEn: "Liturgy of the Word",
        gesture: "point",
        title: "2nd Reading",
        text: "📜 The second reading is proclaimed from the New Testament letters.",
    },
    {
        part: "2. Liturgy of the Word",
        partEn: "Liturgy of the Word",
        gesture: "ourFather",
        title: "Gospel Acclamation",
        text: "🙌 The assembly rises and acclaims the Gospel.",
    },
    {
        part: "2. Liturgy of the Word",
        partEn: "Liturgy of the Word",
        gesture: "point",
        title: "Gospel",
        text: "✝️ The Holy Gospel is proclaimed.",
    },
    {
        part: "2. Liturgy of the Word",
        partEn: "Liturgy of the Word",
        gesture: "point",
        title: "Homily",
        text: "🕊️ The homily explains and applies the Word of God.",
    },
    {
        part: "2. Liturgy of the Word",
        partEn: "Liturgy of the Word",
        gesture: "pray",
        title: "Apostles' Creed",
        text: "🤍 The faithful profess the Apostles' Creed together.",
    },
    {
        part: "2. Liturgy of the Word",
        partEn: "Liturgy of the Word",
        gesture: "ourFather",
        title: "Universal Prayer",
        text: "🫶 The community prays for the Church and the world.",
    },
    {
        part: "3. Liturgy of the Eucharist",
        partEn: "Liturgy of the Eucharist",
        gesture: "hold",
        title: "Preparation of the Gifts",
        text: "🍞 Bread and wine are brought forward to the altar.",
    },
    {
        part: "3. Liturgy of the Eucharist",
        partEn: "Liturgy of the Eucharist",
        gesture: "pray",
        title: "Prayer over the Offerings",
        text: "🙏 The celebrant invites all to pray over the gifts.",
    },
    {
        part: "3. Liturgy of the Eucharist",
        partEn: "Liturgy of the Eucharist",
        gesture: "ourFather",
        title: "Sanctus",
        text: "🎶 Holy, Holy, Holy Lord God of hosts.",
    },
    {
        part: "3. Liturgy of the Eucharist",
        partEn: "Liturgy of the Eucharist",
        gesture: "lift",
        title: "Eucharistic Prayer",
        text: "✨ The Church gives thanks and praise through the Eucharistic Prayer.",
    },
    {
        part: "3. Liturgy of the Eucharist",
        partEn: "Liturgy of the Eucharist",
        gesture: "ourFather",
        title: "The Lord's Prayer",
        text: "👐 The faithful pray the Lord's Prayer together.",
    },
    {
        part: "3. Liturgy of the Eucharist",
        partEn: "Liturgy of the Eucharist",
        gesture: "point",
        title: "Sign of Peace",
        text: "🤝 The sign of peace is exchanged in charity.",
    },
    {
        part: "3. Liturgy of the Eucharist",
        partEn: "Liturgy of the Eucharist",
        gesture: "pray",
        title: "Lamb of God",
        text: "🙏 Lamb of God, you take away the sins of the world, have mercy on us.",
    },
    {
        part: "3. Liturgy of the Eucharist",
        partEn: "Liturgy of the Eucharist",
        gesture: "hold",
        title: "Communion",
        text: "🍞 The faithful receive Holy Communion with reverence.",
    },
    {
        part: "4. Concluding Rites",
        partEn: "Concluding Rites",
        gesture: "pray",
        title: "Blessing",
        text: "🔔 The celebrant blesses the people before sending forth.",
    },
    {
        part: "4. Concluding Rites",
        partEn: "Concluding Rites",
        gesture: "point",
        title: "Dismissal",
        text: "🔔 The people are blessed and sent forth to live the Gospel.",
    },
];

function buildMassFlowNavigation() {
    const groupsContainer = document.getElementById("mass-nav-groups");
    if (!groupsContainer || groupsContainer.dataset.built === "true") {
        return;
    }

    const groups = new Map();
    MASS_FLOW_STEPS.forEach((step, index) => {
        const key = `${step.part}|${step.partEn}`;
        if (!groups.has(key)) {
            groups.set(key, {
                part: step.part,
                partEn: step.partEn,
                indices: [],
            });
        }
        groups.get(key).indices.push(index);
    });

    groupsContainer.innerHTML = "";
    groups.forEach((group) => {
        const section = document.createElement("section");
        section.className = "mass-nav-group";

        const firstIndex = group.indices[0];
        const headerButton = document.createElement("button");
        headerButton.type = "button";
        headerButton.className = "mass-nav-part-btn";
        headerButton.dataset.stepIndex = String(firstIndex);
        headerButton.innerHTML = `<span>${group.part}</span><small>${group.partEn}</small>`;
        section.appendChild(headerButton);

        const list = document.createElement("div");
        list.className = "mass-nav-step-list";
        group.indices.forEach((stepIndex) => {
            const step = MASS_FLOW_STEPS[stepIndex];
            const button = document.createElement("button");
            button.type = "button";
            button.className = "mass-nav-step-btn";
            button.dataset.stepIndex = String(stepIndex);
            button.innerHTML = `<span class="mass-nav-step-order">${stepIndex + 1}</span><span class="mass-nav-step-title">${step.title}</span>`;
            list.appendChild(button);
        });
        section.appendChild(list);
        groupsContainer.appendChild(section);
    });

    groupsContainer.dataset.built = "true";
}

function setMassFlowStatus(text) {
    const status = document.getElementById("mass-nav-status");
    if (status) {
        status.textContent = text;
    }
}

function setMassFlowStepState(activeStepIndex, massActive) {
    const buttons = document.querySelectorAll(".mass-nav-step-btn[data-step-index], .mass-nav-part-btn[data-step-index]");
    buttons.forEach((button) => {
        const stepIndex = Number(button.dataset.stepIndex);
        if (!Number.isFinite(stepIndex)) {
            return;
        }
        button.classList.toggle("is-active", stepIndex === activeStepIndex);
        button.classList.toggle("is-complete", massActive && activeStepIndex >= 0 && stepIndex < activeStepIndex);
    });
}

function setMassNavigatorVisible(isVisible) {
    const nav = document.getElementById("mass-navigator");
    if (!nav) {
        return;
    }
    nav.classList.toggle("is-active", isVisible);
    nav.setAttribute("aria-hidden", isVisible ? "false" : "true");
}

function bindMassNavigator() {
    if (APP_STATE.massNavBound) {
        return;
    }
    const nav = document.getElementById("mass-navigator");
    if (!nav) {
        return;
    }

    nav.addEventListener("click", (event) => {
        const button = event.target.closest(".mass-nav-step-btn[data-step-index], .mass-nav-part-btn[data-step-index]");
        if (!button || !APP_STATE.threeWorld) {
            return;
        }
        const stepIndex = Number(button.dataset.stepIndex);
        if (!Number.isFinite(stepIndex) || typeof APP_STATE.threeWorld.jumpToMassStep !== "function") {
            return;
        }
        APP_STATE.threeWorld.jumpToMassStep(stepIndex);
    });

    APP_STATE.massNavBound = true;
}

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
            setLiturgySubtitle("↩️ Turned left.");
        } else if (command === "move-right") {
            world.nudgeMove(1, 0);
            setLiturgySubtitle("↪️ Turned right.");
        } else if (command === "move-forward") {
            world.nudgeMove(0, -1);
            setLiturgySubtitle("⬆️ Moved forward.");
        } else if (command === "move-back") {
            world.nudgeMove(0, 1);
            setLiturgySubtitle("⬇️ Moved backward.");
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
        corpusSkin: new THREE.MeshLambertMaterial({
            color: 0xf0caa3,
            emissive: 0x2a1a11,
            emissiveIntensity: 0.14,
        }),
        corpusCloth: new THREE.MeshLambertMaterial({
            color: 0xf7f3e7,
            emissive: 0x231a13,
            emissiveIntensity: 0.06,
        }),
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
    corpusGroup.position.set(0, 0, 0.56);
    altarGroup.add(corpusGroup);

    const corpusTorso = new THREE.Mesh(new THREE.BoxGeometry(0.72, 2.2, 0.35), materials.corpusSkin);
    corpusTorso.position.set(0, 6.32, 0.24);
    corpusTorso.castShadow = true;
    corpusTorso.name = "corpus-torso";
    corpusGroup.add(corpusTorso);

    const corpusHead = new THREE.Mesh(new THREE.BoxGeometry(0.58, 0.62, 0.42), materials.corpusSkin);
    corpusHead.position.set(0, 7.74, 0.24);
    corpusHead.castShadow = true;
    corpusHead.name = "corpus-head";
    corpusGroup.add(corpusHead);

    const corpusArms = new THREE.Mesh(new THREE.BoxGeometry(2.7, 0.32, 0.3), materials.corpusSkin);
    corpusArms.position.set(0, 7.3, 0.24);
    corpusArms.castShadow = true;
    corpusArms.name = "corpus-arms";
    corpusGroup.add(corpusArms);

    const corpusLeftLeg = new THREE.Mesh(new THREE.BoxGeometry(0.28, 1.15, 0.26), materials.corpusSkin);
    corpusLeftLeg.position.set(-0.14, 4.84, 0.24);
    corpusLeftLeg.castShadow = true;
    corpusLeftLeg.name = "corpus-left-leg";
    corpusGroup.add(corpusLeftLeg);

    const corpusRightLeg = new THREE.Mesh(new THREE.BoxGeometry(0.28, 1.15, 0.26), materials.corpusSkin);
    corpusRightLeg.position.set(0.14, 4.84, 0.24);
    corpusRightLeg.castShadow = true;
    corpusRightLeg.name = "corpus-right-leg";
    corpusGroup.add(corpusRightLeg);

    const corpusCloth = new THREE.Mesh(new THREE.BoxGeometry(0.94, 0.5, 0.32), materials.corpusCloth);
    corpusCloth.position.set(0, 5.52, 0.26);
    corpusCloth.castShadow = true;
    corpusCloth.name = "corpus-cloth";
    corpusGroup.add(corpusCloth);

    const corpusLight = new THREE.PointLight(0xffe3bf, 0.62, 11, 2);
    corpusLight.position.set(0, 6.8, 1.35);
    altarGroup.add(corpusLight);

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

    const collisionObstacles = [];
    const playerCollisionRadius = 0.56;
    const worldBounds = { minX: -13.8, maxX: 13.8, minZ: -14.6, maxZ: 14.8 };
    function addCollisionRect(centerX, centerZ, width, depth, extra = playerCollisionRadius) {
        const halfW = width * 0.5 + extra;
        const halfD = depth * 0.5 + extra;
        collisionObstacles.push({
            minX: centerX - halfW,
            maxX: centerX + halfW,
            minZ: centerZ - halfD,
            maxZ: centerZ + halfD,
        });
    }

    // Keep distance from the altar table.
    addCollisionRect(altarGroup.position.x, altarGroup.position.z, 7.2, 4.0, playerCollisionRadius + 0.08);

    for (let row = 0; row < 4; row += 1) {
        for (let side = -1; side <= 1; side += 2) {
            const pew = new THREE.Mesh(new THREE.BoxGeometry(5.8, 1.0, 1.45), materials.wood);
            pew.position.set(side * 7.2, 0.55, row * 3.3 - 2.6);
            pew.castShadow = true;
            pew.receiveShadow = true;
            root.add(pew);
            addCollisionRect(pew.position.x, pew.position.z, 5.8, 1.45);

            const back = new THREE.Mesh(new THREE.BoxGeometry(5.8, 1.2, 0.35), materials.darkWood);
            // Move backrest behind the seated direction (toward nave) so pews face the altar.
            back.position.set(side * 7.2, 1.25, row * 3.3 - 1.85);
            root.add(back);
            addCollisionRect(back.position.x, back.position.z, 5.8, 0.35);
        }
    }

    const selected = CHARACTER_CONFIG[APP_STATE.selectedCharacter] || CHARACTER_CONFIG.nun;
    const isPriest = APP_STATE.selectedCharacter === "priest";

    const playerRig = new THREE.Group();
    playerRig.position.set(0, 0, 10.8);
    root.add(playerRig);

    const textureLoader = new THREE.TextureLoader();
    const playerTextures = {
        front: textureLoader.load(selected.frontImage),
        back: textureLoader.load(selected.backImage || selected.frontImage),
    };
    Object.values(playerTextures).forEach((texture) => {
        if ("colorSpace" in texture) {
            texture.colorSpace = THREE.SRGBColorSpace;
        }
        texture.magFilter = THREE.NearestFilter;
        texture.minFilter = THREE.NearestFilter;
    });

    const playerSpriteMaterial = new THREE.MeshBasicMaterial({
        map: playerTextures.front,
        transparent: true,
        alphaTest: 0.02,
        side: THREE.DoubleSide,
        depthWrite: false,
    });
    const playerSprite = new THREE.Mesh(new THREE.PlaneGeometry(2.85, 3.35), playerSpriteMaterial);
    const playerSpriteBaseScale = { x: 2.85, y: 3.35 };
    playerSprite.scale.set(playerSpriteBaseScale.x, playerSpriteBaseScale.y, 1);
    playerSprite.position.set(0, 1.62, 0.14);
    playerSprite.renderOrder = 3;
    playerRig.add(playerSprite);

    const itemMaterial = new THREE.MeshLambertMaterial({ color: 0xc6a278 });
    const liturgyItem = new THREE.Mesh(new THREE.BoxGeometry(0.52, 0.64, 0.26), itemMaterial);
    liturgyItem.visible = false;
    playerRig.add(liturgyItem);

    // Palette values were sampled from the actual PNG sprites to keep visual consistency.
    const spritePalette = isPriest
        ? {
            robePrimary: 0x3f3d37,
            robeSecondary: 0x2f2d29,
            trim: 0xefe1d0,
            skin: 0xd8ad90,
        }
        : {
            robePrimary: 0x272722,
            robeSecondary: 0x1d1d18,
            trim: 0xf6f2eb,
            skin: 0xe8c4a7,
        };

    const armStyle = isPriest
        ? {
            shoulderX: 0.74,
            shoulderY: 2.02,
            shoulderZ: 0.22,
            upperWidth: 0.28,
            upperLength: 0.78,
            lowerWidth: 0.24,
            lowerLength: 0.72,
            elbowDrop: 0.73,
            handRadius: 0.1,
            cuffWidth: 0.22,
            cuffLength: 0.1,
            chestCoverRadius: 0.28,
            chestCoverY: 1.95,
            handDepthFront: 0.026,
        }
        : {
            shoulderX: 0.7,
            shoulderY: 2.0,
            shoulderZ: 0.22,
            upperWidth: 0.26,
            upperLength: 0.74,
            lowerWidth: 0.22,
            lowerLength: 0.68,
            elbowDrop: 0.7,
            handRadius: 0.095,
            cuffWidth: 0.2,
            cuffLength: 0.09,
            chestCoverRadius: 0.3,
            chestCoverY: 1.9,
            handDepthFront: 0.024,
        };

    const sleeveMaterial = new THREE.MeshLambertMaterial({
        color: spritePalette.robePrimary,
        transparent: true,
        opacity: 0.8,
        side: THREE.DoubleSide,
        depthWrite: false,
    });
    const sleeveShadeMaterial = new THREE.MeshLambertMaterial({
        color: spritePalette.robeSecondary,
        transparent: true,
        opacity: 0.58,
        side: THREE.DoubleSide,
        depthWrite: false,
    });
    const cuffMaterial = new THREE.MeshLambertMaterial({
        color: spritePalette.trim,
        transparent: true,
        opacity: 0.96,
        side: THREE.DoubleSide,
        depthWrite: false,
    });
    const handOverlayMaterial = new THREE.MeshLambertMaterial({
        color: spritePalette.skin,
        transparent: true,
        opacity: 0.98,
        side: THREE.DoubleSide,
        depthWrite: false,
    });

    function createArm(side) {
        const shoulder = new THREE.Object3D();
        shoulder.position.set(side * armStyle.shoulderX, armStyle.shoulderY, armStyle.shoulderZ - 0.19);

        const upper = new THREE.Mesh(new THREE.PlaneGeometry(armStyle.upperWidth, armStyle.upperLength), sleeveMaterial);
        upper.position.set(0, -armStyle.upperLength * 0.5, -0.02);
        shoulder.add(upper);
        const upperShade = new THREE.Mesh(
            new THREE.PlaneGeometry(armStyle.upperWidth * 0.65, armStyle.upperLength * 0.9),
            sleeveShadeMaterial,
        );
        upperShade.position.set(side * 0.015, -armStyle.upperLength * 0.52, -0.01);
        shoulder.add(upperShade);
        const upperCap = new THREE.Mesh(new THREE.CircleGeometry(armStyle.upperWidth * 0.44, 14), sleeveMaterial);
        upperCap.position.set(0, -armStyle.upperLength * 0.03, -0.014);
        shoulder.add(upperCap);

        const elbow = new THREE.Object3D();
        elbow.position.y = -armStyle.elbowDrop;
        shoulder.add(elbow);
        const elbowCap = new THREE.Mesh(new THREE.CircleGeometry(armStyle.lowerWidth * 0.5, 14), sleeveMaterial);
        elbowCap.position.set(0, -0.03, -0.014);
        elbow.add(elbowCap);

        const lower = new THREE.Mesh(new THREE.PlaneGeometry(armStyle.lowerWidth, armStyle.lowerLength), sleeveMaterial);
        lower.position.set(0, -armStyle.lowerLength * 0.48, -0.02);
        elbow.add(lower);
        const lowerShade = new THREE.Mesh(
            new THREE.PlaneGeometry(armStyle.lowerWidth * 0.62, armStyle.lowerLength * 0.9),
            sleeveShadeMaterial,
        );
        lowerShade.position.set(side * 0.012, -armStyle.lowerLength * 0.5, -0.01);
        elbow.add(lowerShade);

        const cuff = new THREE.Mesh(new THREE.PlaneGeometry(armStyle.cuffWidth, armStyle.cuffLength), cuffMaterial);
        cuff.position.set(0, -armStyle.lowerLength * 0.92, -0.012);
        elbow.add(cuff);

        const hand = new THREE.Mesh(new THREE.CircleGeometry(armStyle.handRadius, 16), handOverlayMaterial);
        hand.position.set(0, -armStyle.lowerLength * 1.08, armStyle.handDepthFront);
        elbow.add(hand);

        [upper, upperShade, upperCap, elbowCap, lower, lowerShade, cuff].forEach((mesh) => {
            mesh.renderOrder = 1.5;
            mesh.castShadow = false;
            mesh.receiveShadow = false;
        });
        hand.renderOrder = 2.5;
        hand.castShadow = false;
        hand.receiveShadow = false;

        playerRig.add(shoulder);
        return {
            shoulder,
            elbow,
            hand,
            segments: [upper, upperShade, upperCap, elbowCap, lower, lowerShade, cuff],
        };
    }

    const leftArm = createArm(-1);
    const rightArm = createArm(1);
    const chestCover = new THREE.Mesh(
        new THREE.CircleGeometry(armStyle.chestCoverRadius, 20),
        new THREE.MeshLambertMaterial({
            color: spritePalette.robePrimary,
            transparent: true,
            opacity: 0.96,
            side: THREE.DoubleSide,
            depthWrite: false,
        }),
    );
    chestCover.position.set(0, armStyle.chestCoverY, armStyle.shoulderZ + 0.01);
    chestCover.renderOrder = 2.2;
    playerRig.add(chestCover);
    chestCover.visible = false;
    [...leftArm.segments, ...rightArm.segments].forEach((segment) => {
        segment.visible = false;
    });

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

    const gesturePoses = isPriest
        ? {
            idle: {
                left: { ux: -0.42, uy: 0.24, uz: 0.46, lx: -0.3, ly: 0, lz: 0 },
                right: { ux: -0.42, uy: -0.24, uz: -0.46, lx: -0.3, ly: 0, lz: 0 },
            },
            point: {
                left: { ux: -0.68, uy: 0.22, uz: 0.58, lx: -0.4, ly: 0, lz: 0 },
                right: { ux: -1.08, uy: -0.3, uz: -0.74, lx: -0.16, ly: 0, lz: 0 },
            },
            hold: {
                left: { ux: -1.12, uy: 0.08, uz: 0.62, lx: -0.82, ly: 0, lz: 0 },
                right: { ux: -1.12, uy: -0.08, uz: -0.62, lx: -0.82, ly: 0, lz: 0 },
            },
            lift: {
                left: { ux: -1.9, uy: 0.14, uz: 0.34, lx: -0.08, ly: 0, lz: 0 },
                right: { ux: -1.9, uy: -0.14, uz: -0.34, lx: -0.08, ly: 0, lz: 0 },
            },
            pray: {
                left: { ux: -1.04, uy: 0.04, uz: 0.84, lx: -0.78, ly: 0, lz: 0 },
                right: { ux: -1.04, uy: -0.04, uz: -0.84, lx: -0.78, ly: 0, lz: 0 },
            },
            ourFather: {
                left: { ux: -0.82, uy: 0.28, uz: 1.22, lx: -0.64, ly: 0, lz: 0 },
                right: { ux: -0.82, uy: -0.28, uz: -1.22, lx: -0.64, ly: 0, lz: 0 },
            },
        }
        : {
            idle: {
                left: { ux: -0.48, uy: 0.24, uz: 0.48, lx: -0.3, ly: 0, lz: 0 },
                right: { ux: -0.48, uy: -0.24, uz: -0.48, lx: -0.3, ly: 0, lz: 0 },
            },
            point: {
                left: { ux: -0.76, uy: 0.24, uz: 0.62, lx: -0.42, ly: 0, lz: 0 },
                right: { ux: -1.16, uy: -0.28, uz: -0.8, lx: -0.12, ly: 0, lz: 0 },
            },
            hold: {
                left: { ux: -1.16, uy: 0.1, uz: 0.7, lx: -0.84, ly: 0, lz: 0 },
                right: { ux: -1.16, uy: -0.1, uz: -0.7, lx: -0.84, ly: 0, lz: 0 },
            },
            lift: {
                left: { ux: -1.84, uy: 0.17, uz: 0.3, lx: -0.06, ly: 0, lz: 0 },
                right: { ux: -1.84, uy: -0.17, uz: -0.3, lx: -0.06, ly: 0, lz: 0 },
            },
            pray: {
                left: { ux: -1.0, uy: 0.06, uz: 0.9, lx: -0.78, ly: 0, lz: 0 },
                right: { ux: -1.0, uy: -0.06, uz: -0.9, lx: -0.78, ly: 0, lz: 0 },
            },
            ourFather: {
                left: { ux: -0.76, uy: 0.3, uz: 1.28, lx: -0.62, ly: 0, lz: 0 },
                right: { ux: -0.76, uy: -0.3, uz: -1.28, lx: -0.62, ly: 0, lz: 0 },
            },
        };

    const signCrossPoses = isPriest
        ? [
            {
                left: { ux: -0.92, uy: 0.08, uz: 0.66, lx: -0.56, ly: 0, lz: 0 },
                right: { ux: -1.78, uy: -0.14, uz: -0.08, lx: -0.52, ly: 0, lz: 0 },
            },
            {
                left: { ux: -0.92, uy: 0.08, uz: 0.66, lx: -0.56, ly: 0, lz: 0 },
                right: { ux: -1.16, uy: 0.04, uz: 0.2, lx: -0.18, ly: 0, lz: 0 },
            },
            {
                left: { ux: -0.92, uy: 0.08, uz: 0.66, lx: -0.56, ly: 0, lz: 0 },
                right: { ux: -0.94, uy: 0.6, uz: 0.38, lx: -0.06, ly: 0, lz: 0 },
            },
            {
                left: { ux: -0.92, uy: 0.08, uz: 0.66, lx: -0.56, ly: 0, lz: 0 },
                right: { ux: -0.94, uy: -0.6, uz: -0.38, lx: -0.06, ly: 0, lz: 0 },
            },
        ]
        : [
            {
                left: { ux: -0.9, uy: 0.1, uz: 0.72, lx: -0.58, ly: 0, lz: 0 },
                right: { ux: -1.72, uy: -0.15, uz: -0.08, lx: -0.46, ly: 0, lz: 0 },
            },
            {
                left: { ux: -0.9, uy: 0.1, uz: 0.72, lx: -0.58, ly: 0, lz: 0 },
                right: { ux: -1.08, uy: 0.06, uz: 0.24, lx: -0.16, ly: 0, lz: 0 },
            },
            {
                left: { ux: -0.9, uy: 0.1, uz: 0.72, lx: -0.58, ly: 0, lz: 0 },
                right: { ux: -0.9, uy: 0.64, uz: 0.42, lx: -0.04, ly: 0, lz: 0 },
            },
            {
                left: { ux: -0.9, uy: 0.1, uz: 0.72, lx: -0.58, ly: 0, lz: 0 },
                right: { ux: -0.9, uy: -0.64, uz: -0.42, lx: -0.04, ly: 0, lz: 0 },
            },
        ];

    function setGesturePose(gesture) {
        const pose = gesturePoses[gesture] || gesturePoses.idle;
        setArmTargets(pose.left, pose.right);
    }

    const actionState = {
        currentGesture: "idle",
        signCrossActive: false,
        signCrossTime: 0,
        massActive: false,
        massIndex: 0,
        currentMassStepIndex: -1,
        massTimer: 0,
        massStepDuration: 2.8,
    };

    function narrateGesture(name, prefix = "") {
        const message = GESTURE_NARRATION[name] || GESTURE_NARRATION.idle;
        const merged = prefix ? `${prefix} ${message}` : message;
        setLiturgySubtitle(merged);
        setHudButtonsState(name, actionState.massActive);
    }

    function shouldShowOverlayHands(gesture) {
        // Keep sprite's own hands for calm poses to avoid doubled-hand look.
        return ["point", "hold", "lift", "ourFather", "signCross"].includes(gesture);
    }

    function setOverlayHandsVisible(isVisible) {
        leftArm.hand.visible = isVisible;
        rightArm.hand.visible = isVisible;
    }

    function triggerGesture(name, prefix = "", massStepIndex = -1) {
        actionState.currentGesture = name;
        actionState.massTimer = actionState.massStepDuration;
        if (Number.isInteger(massStepIndex)) {
            actionState.currentMassStepIndex = massStepIndex;
        } else if (!actionState.massActive) {
            actionState.currentMassStepIndex = -1;
        }
        if (name === "signCross") {
            actionState.signCrossActive = true;
            actionState.signCrossTime = 0;
            setGesturePose("pray");
            setOverlayHandsVisible(true);
            narrateGesture("signCross", prefix);
            setMassFlowStepState(actionState.currentMassStepIndex, actionState.massActive);
            return;
        }
        actionState.signCrossActive = false;
        setGesturePose(name);
        setOverlayHandsVisible(shouldShowOverlayHands(name));
        narrateGesture(name, prefix);
        setMassFlowStepState(actionState.currentMassStepIndex, actionState.massActive);
    }

    function advanceMassStep() {
        const stepIndex = actionState.massIndex % MASS_FLOW_STEPS.length;
        const step = MASS_FLOW_STEPS[stepIndex];
        const next = step.gesture;
        const stepNumber = stepIndex + 1;
        const prefix = `🎼 ${step.part} · ${step.title} (${stepNumber}/${MASS_FLOW_STEPS.length})`;
        actionState.massIndex += 1;
        triggerGesture(next, `${prefix} ${step.text}`, stepIndex);
        setMassFlowStatus(`▶️ Auto: ${step.part} (${step.partEn}) > ${step.title}`);
    }

    function jumpToMassStep(stepIndex) {
        if (!Number.isInteger(stepIndex) || stepIndex < 0 || stepIndex >= MASS_FLOW_STEPS.length) {
            return;
        }
        if (actionState.massActive) {
            actionState.massActive = false;
        }
        const step = MASS_FLOW_STEPS[stepIndex];
        actionState.massIndex = stepIndex;
        triggerGesture(step.gesture, `📍 ${step.part} · ${step.title} — ${step.text}`, stepIndex);
        setDialogue(`Jumped to ${step.part} (${step.partEn}) - ${step.title}.`);
        setMassFlowStatus(`📌 Current: ${step.part} (${step.partEn}) > ${step.title}`);
    }

    function setMassMode(isActive) {
        if (isActive === actionState.massActive) {
            return;
        }
        actionState.massActive = isActive;
        if (actionState.massActive) {
            actionState.massIndex = actionState.currentMassStepIndex >= 0 ? actionState.currentMassStepIndex : 0;
            advanceMassStep();
            setDialogue("Mass sequence started. Press M again to stop.");
            setMassFlowStatus("▶️ Auto Mass progression running...");
            return;
        }
        triggerGesture("idle", "", -1);
        setLiturgySubtitle("⏸️ Mass sequence paused. Select any gesture manually.");
        setDialogue("Mass sequence paused.");
        setMassFlowStatus("⏸️ Paused. Click a step to jump there.");
    }

    triggerGesture("idle", "", -1);
    setMassFlowStepState(-1, false);
    setMassFlowStatus("🧭 Choose a part and click a detailed step.");

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
    let forwardSpeed = 0;
    const playerVelocityXZ = new THREE.Vector2(0, 0);
    const playerMotion = {
        speed: 7.1,
        acceleration: 10.5,
        deceleration: 8.8,
        gravity: 18,
        jump: 8,
        onGround: true,
        jumpLatch: false,
        groundY: 0,
    };
    const turnRate = 2.6;

    function attemptJump() {
        if (playerMotion.onGround && !playerMotion.jumpLatch) {
            playerVelocity.y = playerMotion.jump;
            playerMotion.onGround = false;
            playerMotion.jumpLatch = true;
        }
    }

    function normalizeAngle(angle) {
        let wrapped = angle;
        while (wrapped <= -Math.PI) wrapped += Math.PI * 2;
        while (wrapped > Math.PI) wrapped -= Math.PI * 2;
        return wrapped;
    }

    function updateDirectionFromYaw() {
        moveDirection.set(Math.sin(facingState.yaw), 0, -Math.cos(facingState.yaw));
        cameraBehindDirection.set(-moveDirection.x, 0, -moveDirection.z);
    }

    function collidesAt(x, z) {
        return collisionObstacles.some((obstacle) =>
            x > obstacle.minX &&
            x < obstacle.maxX &&
            z > obstacle.minZ &&
            z < obstacle.maxZ
        );
    }

    function attemptMoveTo(nextX, nextZ) {
        const currentX = playerRig.position.x;
        const currentZ = playerRig.position.z;
        let resolvedX = THREE.MathUtils.clamp(nextX, worldBounds.minX, worldBounds.maxX);
        let resolvedZ = THREE.MathUtils.clamp(nextZ, worldBounds.minZ, worldBounds.maxZ);
        let blocked = false;

        if (collidesAt(resolvedX, currentZ)) {
            resolvedX = currentX;
            blocked = true;
        }
        if (collidesAt(resolvedX, resolvedZ)) {
            resolvedZ = currentZ;
            blocked = true;
        }
        if (collidesAt(resolvedX, resolvedZ)) {
            resolvedX = currentX;
            resolvedZ = currentZ;
            blocked = true;
        }

        playerRig.position.x = resolvedX;
        playerRig.position.z = resolvedZ;
        return blocked;
    }

    function nudgeMove(dx, dz) {
        if (dx !== 0) {
            facingState.yaw = normalizeAngle(facingState.yaw + dx * 0.3);
            updateDirectionFromYaw();
            return;
        }
        if (dz !== 0) {
            const directionSign = dz < 0 ? 1 : -1;
            const stepDistance = 1.12 * directionSign;
            const targetX = playerRig.position.x + moveDirection.x * stepDistance;
            const targetZ = playerRig.position.z + moveDirection.z * stepDistance;
            attemptMoveTo(targetX, targetZ);
        }
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

        const signPose =
            phase < 1 ? signCrossPoses[0]
            : phase < 2 ? signCrossPoses[1]
            : phase < 3 ? signCrossPoses[2]
            : signCrossPoses[3];
        setArmTargets(signPose.left, signPose.right);

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
    const moveDirection = new THREE.Vector3(0, 0, -1);
    const cameraBehindDirection = new THREE.Vector3(0, 0, 1);
    const facingState = {
        yaw: 0,
    };
    const clock = new THREE.Clock();
    const spriteFacingState = {
        xDir: 1,
        walkPhase: 0,
        facingBack: false,
        motionBlend: 0,
    };

    updateDirectionFromYaw();

    function updatePlayerSpriteMotion(velocityX, velocityZ, turnInput, dt) {
        const speed = Math.hypot(velocityX, velocityZ);
        const signedForwardSpeed = velocityX * moveDirection.x + velocityZ * moveDirection.z;
        const moving = speed > 0.18;

        if (moving) {
            const shouldFaceBack = signedForwardSpeed >= -0.02;
            if (spriteFacingState.facingBack !== shouldFaceBack) {
                spriteFacingState.facingBack = shouldFaceBack;
                playerSpriteMaterial.map = shouldFaceBack ? playerTextures.back : playerTextures.front;
                playerSpriteMaterial.needsUpdate = true;
            }
            if (Math.abs(velocityX) > 0.08) {
                spriteFacingState.xDir = velocityX < 0 ? -1 : 1;
            } else if (Math.abs(turnInput) > 0.05) {
                spriteFacingState.xDir = turnInput < 0 ? -1 : 1;
            }
        } else if (spriteFacingState.facingBack) {
            spriteFacingState.facingBack = false;
            playerSpriteMaterial.map = playerTextures.front;
            playerSpriteMaterial.needsUpdate = true;
        } else if (Math.abs(turnInput) > 0.05) {
            spriteFacingState.xDir = turnInput < 0 ? -1 : 1;
        }

        const blendTarget = moving && playerMotion.onGround ? 1 : 0;
        spriteFacingState.motionBlend += (blendTarget - spriteFacingState.motionBlend) * Math.min(dt * 8, 1);
        spriteFacingState.walkPhase += dt * (4 + speed * 1.6);

        const walkBob = spriteFacingState.motionBlend > 0.02
            ? Math.sin(spriteFacingState.walkPhase) * (0.04 + spriteFacingState.motionBlend * 0.08)
            : Math.sin(performance.now() * 0.0035) * 0.03;
        const squash = 1 - spriteFacingState.motionBlend * 0.02 + Math.cos(spriteFacingState.walkPhase) * spriteFacingState.motionBlend * 0.025;
        const stretchX = 1 + spriteFacingState.motionBlend * 0.03;
        const tiltTarget = THREE.MathUtils.clamp((-velocityX * 0.012) + turnInput * -0.06, -0.16, 0.16);

        playerSprite.scale.x = playerSpriteBaseScale.x * spriteFacingState.xDir * stretchX;
        playerSprite.scale.y = playerSpriteBaseScale.y * squash;
        playerSprite.position.y = 1.62 + walkBob + Math.max(playerRig.position.y, 0) * 0.06;
        playerSpriteMaterial.rotation = THREE.MathUtils.lerp(
            playerSpriteMaterial.rotation,
            tiltTarget,
            Math.min(dt * 8, 1),
        );
    }

    function applyArmSecondaryMotion(speed) {
        if (speed < 0.1 || !playerMotion.onGround) {
            return;
        }
        const energy = Math.min(speed / playerMotion.speed, 1);
        const sway = Math.sin(spriteFacingState.walkPhase * 1.1) * 0.08 * energy;
        leftArm.shoulder.rotation.z += sway * 0.55;
        rightArm.shoulder.rotation.z -= sway * 0.55;
        leftArm.elbow.rotation.x += Math.abs(sway) * 0.18;
        rightArm.elbow.rotation.x += Math.abs(sway) * 0.18;
    }

    function animate() {
        const dt = Math.min(clock.getDelta(), 0.05);

        updateMassSequence(dt);
        updateSignOfCross(dt);

        const left = keyState.has("ArrowLeft") || keyState.has("KeyA");
        const right = keyState.has("ArrowRight") || keyState.has("KeyD");
        const up = keyState.has("ArrowUp") || keyState.has("KeyW");
        const down = keyState.has("ArrowDown") || keyState.has("KeyS");
        const jump = keyState.has("Space");

        const turnInput = (right ? 1 : 0) - (left ? 1 : 0);
        const throttleInput = (up ? 1 : 0) - (down ? 1 : 0);
        facingState.yaw = normalizeAngle(facingState.yaw + turnInput * turnRate * dt);
        updateDirectionFromYaw();

        const targetForwardSpeed = throttleInput * playerMotion.speed;
        const acceleration = throttleInput !== 0 ? playerMotion.acceleration : playerMotion.deceleration;
        const blend = Math.min(dt * acceleration, 1);
        forwardSpeed += (targetForwardSpeed - forwardSpeed) * blend;
        playerVelocityXZ.set(moveDirection.x * forwardSpeed, moveDirection.z * forwardSpeed);

        const blocked = attemptMoveTo(
            playerRig.position.x + playerVelocityXZ.x * dt,
            playerRig.position.z + playerVelocityXZ.y * dt,
        );
        if (blocked) {
            forwardSpeed *= 0.15;
            playerVelocityXZ.set(0, 0);
        }

        const horizontalSpeed = playerVelocityXZ.length();
        playerRig.rotation.y = facingState.yaw;

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

        updateArmPoseSmoothing(dt);
        applyArmSecondaryMotion(horizontalSpeed);
        updateLiturgyItem();
        updatePlayerSpriteMotion(playerVelocityXZ.x, playerVelocityXZ.y, turnInput, dt);

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

        cameraTarget.copy(playerRig.position);
        cameraTarget.x += cameraBehindDirection.x * cameraOffset.z;
        cameraTarget.y += cameraOffset.y;
        cameraTarget.z += cameraBehindDirection.z * cameraOffset.z;
        camera.position.lerp(cameraTarget, 0.11);

        cameraLookTarget.copy(playerRig.position);
        cameraLookTarget.x += moveDirection.x * 2.4;
        cameraLookTarget.y += cameraLookOffset.y;
        cameraLookTarget.z += moveDirection.z * 2.4;
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
        jumpToMassStep,
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
    setMassNavigatorVisible(false);
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
    buildMassFlowNavigation();
    bindMassNavigator();
    setLiturgyHudVisible(true);
    setMassNavigatorVisible(true);

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