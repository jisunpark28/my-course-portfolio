/**
 * Handles character interaction and updates the dialogue box.
 * @param {string} character - The ID of the character clicked.
 */
let is3DMode = false;

function handleInteract(character) {
    const dialogueBox = document.getElementById('dialogue-box');
    const charContainer = document.querySelector(`.character-${character}`);
    const charImg = charContainer.querySelector('img');
    
    if (charImg) {
        // 1. 캐릭터 뒷모습으로 변경 (파일이 있는지 꼭 확인!)
        charImg.src = `assets/${character}_back.png`;
        
        // 2. 애니메이션 클래스 추가
        // 부모 container에 추가해야 캐릭터 전체가 움직입니다.
        charContainer.classList.add('walking-into-church');
    }

    // 3. 대사 출력
    if (character === 'priest') {
        dialogueBox.innerText = "Father is entering the church to prepare for Mass...";
    } else {
        dialogueBox.innerText = "Sister is leading you to the sanctuary...";
    }

    // 4. 1.5초 뒤 3D 전환
    setTimeout(() => {
        initThreeJS(character);
    }, 2000);
}


// Three.js 초기화 함수 (마인크래프트 스타일 월드)
function initThreeJS(role) {
    // 1. 기존 UI 정리 (2D 요소들 숨기기)
    document.querySelector('.main-title').style.display = 'none'; 
    document.querySelector('.church-scene').style.display = 'none';
    document.getElementById('dialogue-box').style.display = 'none';
    
    is3DMode = true;

    // 2. 기본 씬 설정
    const scene = new THREE.Scene();
    scene.background = new THREE.Color(0xF5F5DC); // 베이지 배경

    const camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
    const renderer = new THREE.WebGLRenderer({ antialias: true });
    renderer.setSize(window.innerWidth, window.innerHeight);
    document.body.appendChild(renderer.domElement);

    // 3. 바닥 추가
    const floorGeometry = new THREE.BoxGeometry(20, 0.5, 40);
    const floorMaterial = new THREE.MeshLambertMaterial({ color: 0xD2B48C });
    const floor = new THREE.Mesh(floorGeometry, floorMaterial);
    scene.add(floor);

    // 4. 조명 설정
    const ambientLight = new THREE.AmbientLight(0xffffff, 0.6);
    scene.add(ambientLight);

    const sunLight = new THREE.DirectionalLight(0xffffff, 0.8);
    sunLight.position.set(5, 10, 7.5);
    scene.add(sunLight);

    // --- [여기에 합쳐진 코드 시작] ---
    
    // 5. 전례색 데이터 가져오기
    const seasonColorName = getLiturgicalSeason(); 
    const colorMap = {
        'white': 0xffffff, // 부활/성탄
        'green': 0x228B22, // 연중
        'purple': 0x800080 // 사순/대림
    };

    // 6. 제대(Altar) 생성
    const altarGeometry = new THREE.BoxGeometry(4, 1.5, 2);
    const altarMaterial = new THREE.MeshLambertMaterial({ 
        color: colorMap[seasonColorName] 
    });
    const altar = new THREE.Mesh(altarGeometry, altarMaterial);
    altar.position.set(0, 0.75, 0); // 바닥 높이에 맞춰 배치
    scene.add(altar);

    // 7. 십자가(Cross) 생성
    const crossVerticalGeo = new THREE.BoxGeometry(0.2, 1.5, 0.2);
    const crossMaterial = new THREE.MeshLambertMaterial({ color: 0x5D4037 });
    const crossVertical = new THREE.Mesh(crossVerticalGeo, crossMaterial);
    crossVertical.position.set(0, 2.25, -0.5); // 제대 위쪽 뒤편에 배치
    scene.add(crossVertical);

    // --- [합쳐진 코드 끝] ---

    // 8. 역할에 따른 카메라 시점 설정
    if (role === 'priest') {
        camera.position.set(0, 2, -15); // 제대 뒤쪽 (회중석 바라보기)
        camera.lookAt(0, 0, 10);
    } else {
        camera.position.set(0, 2, 15);  // 신자석 (제대 바라보기)
        camera.lookAt(0, 0, -10);
    }

    // 9. 애니메이션 루프
    function animate() {
        if(!is3DMode) return;
        requestAnimationFrame(animate);
        renderer.render(scene, camera);
    }
    animate();
}

// 1. 전례 시기 이름만 '반환'하는 함수
function getLiturgicalSeason() {
    const today = new Date(); // 2026-04-06
    const month = today.getMonth() + 1;
    const date = today.getDate();

    // 2026년 부활 시기 (4/5 ~ 5/23)
    if ((month === 4 && date >= 5) || (month === 5 && date <= 23)) {
        return 'white'; 
    }
    // 사순 시기 (2/18 ~ 4/2)
    if ((month === 2 && date >= 18) || (month === 3) || (month === 4 && date <= 2)) {
        return 'purple';
    }
    // 기본은 연중 시기
    return 'green';
}

// 성당 입장 함수 수정
function enterChurch() {
    const seasonColor = getLiturgicalSeason();
    const bgImage = document.querySelector('.full-bg-image');

    // 파일 이름이 church_inside_white.png 식이라고 가정할 때
    bgImage.src = `assets/church_inside_${seasonColor}.png`;

    document.getElementById('scene-outside').style.display = 'none';
    document.getElementById('scene-inside').style.display = 'block';

    updateDialogue(`Welcome! Today is a day of the ${seasonColor === 'white' ? 'Joyful Easter' : 'Ordinary'} season.`);
}