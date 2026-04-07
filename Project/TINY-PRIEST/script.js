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
};

function setDialogue(text) {
    const dialogueBox = document.getElementById("dialogue-box");
    if (dialogueBox) {
        dialogueBox.textContent = text;
    }
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
    const scene = new THREE.Scene();
    scene.background = new THREE.Color(0xf5f5dc);
    scene.fog = new THREE.Fog(0xf5f5dc, 24, 46);

    const camera = new THREE.PerspectiveCamera(54, window.innerWidth / window.innerHeight, 0.1, 100);

    const renderer = new THREE.WebGLRenderer({ antialias: true });
    renderer.setPixelRatio(Math.min(window.devicePixelRatio || 1, 2));
    renderer.setSize(window.innerWidth, window.innerHeight);
    renderer.outputColorSpace = THREE.SRGBColorSpace;
    container.innerHTML = "";
    container.appendChild(renderer.domElement);

    const ambientLight = new THREE.AmbientLight(0xfff0d0, 1.05);
    const hemiLight = new THREE.HemisphereLight(0xffefcf, 0xc6b38d, 0.55);
    const sunLight = new THREE.DirectionalLight(0xffe4b2, 0.7);
    sunLight.position.set(8, 12, 9);

    scene.add(ambientLight, hemiLight, sunLight);

    const materials = {
        floor: new THREE.MeshLambertMaterial({ color: 0xd8c89e }),
        floorPath: new THREE.MeshLambertMaterial({ color: 0xe7d8b4 }),
        wood: new THREE.MeshLambertMaterial({ color: 0xb18357 }),
        darkWood: new THREE.MeshLambertMaterial({ color: 0x8f673f }),
        wall: new THREE.MeshLambertMaterial({ color: 0xf1e4c6 }),
        altarCloth: new THREE.MeshLambertMaterial({ color: 0x4d9c5a }),
    };

    const root = new THREE.Group();
    scene.add(root);

    const floor = new THREE.Mesh(new THREE.BoxGeometry(30, 1, 24), materials.floor);
    floor.position.set(0, -0.5, 0);
    root.add(floor);

    const centralPath = new THREE.Mesh(new THREE.BoxGeometry(5, 0.18, 22), materials.floorPath);
    centralPath.position.set(0, 0.1, 0);
    root.add(centralPath);

    const backWall = new THREE.Mesh(new THREE.BoxGeometry(30, 8, 1), materials.wall);
    backWall.position.set(0, 4, -11.5);
    root.add(backWall);

    const altarGroup = new THREE.Group();
    altarGroup.position.set(0, 0, -7.8);
    root.add(altarGroup);

    const altarBase = new THREE.Mesh(new THREE.BoxGeometry(7, 2.3, 3.7), materials.wood);
    altarBase.position.y = 1.15;
    altarBase.userData.interactive = true;
    altarGroup.add(altarBase);

    const altarCloth = new THREE.Mesh(new THREE.BoxGeometry(7.2, 0.42, 3.9), materials.altarCloth);
    altarCloth.position.y = 2.52;
    altarCloth.userData.interactive = true;
    altarGroup.add(altarCloth);

    const crossStand = new THREE.Mesh(new THREE.BoxGeometry(0.7, 4, 0.7), materials.darkWood);
    crossStand.position.set(0, 4.2, -0.2);
    crossStand.userData.interactive = true;
    altarGroup.add(crossStand);

    const crossBeam = new THREE.Mesh(new THREE.BoxGeometry(2.7, 0.7, 0.7), materials.darkWood);
    crossBeam.position.set(0, 5.1, -0.2);
    crossBeam.userData.interactive = true;
    altarGroup.add(crossBeam);

    for (let row = 0; row < 3; row += 1) {
        for (let side = -1; side <= 1; side += 2) {
            const pew = new THREE.Mesh(new THREE.BoxGeometry(4.8, 1.1, 1.4), materials.wood);
            pew.position.set(side * 6, 0.55, row * 3.1 - 1.5);
            root.add(pew);
        }
    }

    const raycaster = new THREE.Raycaster();
    const pointer = new THREE.Vector2();
    const interactiveMeshes = [altarBase, altarCloth, crossStand, crossBeam];
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

    const clock = new THREE.Clock();

    function animate() {
        const dt = Math.min(clock.getDelta(), 0.05);

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
    };
}

function applyRoleCamera(role, camera) {
    if (role === "priest") {
        camera.position.set(0, 4.5, -11.5);
        camera.lookAt(0, 2.8, 6);
        return;
    }

    camera.position.set(0, 4.8, 12.5);
    camera.lookAt(0, 2.6, -8);
}

function activateThreeScene(role) {
    const entryScreen = document.getElementById("entry-screen");
    const threeContainer = document.getElementById("three-container");
    const liturgical = getLiturgicalSeason(new Date());

    entryScreen.classList.add("is-hidden");
    setTimeout(() => {
        entryScreen.style.display = "none";
    }, 560);

    threeContainer.classList.add("is-active");
    threeContainer.setAttribute("aria-hidden", "false");

    if (!APP_STATE.threeWorld) {
        APP_STATE.threeWorld = createVoxelChurch(threeContainer);
    }

    APP_STATE.threeWorld.altarCloth.material.color.setHex(liturgical.colorHex);
    APP_STATE.threeWorld.altarCloth.material.needsUpdate = true;

    applyRoleCamera(role, APP_STATE.threeWorld.camera);
    setDialogue(`Today is ${liturgical.season}. Altar cloth color: ${liturgical.colorName}.`);
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
    activateThreeScene(character);
}

window.handleInteract = handleInteract;
window.getLiturgicalSeason = getLiturgicalSeason;