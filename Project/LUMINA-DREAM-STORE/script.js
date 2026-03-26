const shineButtons = document.querySelectorAll('.shine-btn');

shineButtons.forEach((button) => {
    button.addEventListener('click', function () {
        const card = this.closest('.dream-card');
        const lumElement = card.querySelector('.stardust-value');
        const neededElement = card.querySelector('.luminescence-needed');
        const targetValue = parseInt(neededElement.textContent.replace(/[^0-9]/g, ''));

        let currentValue = parseInt(lumElement.textContent);
        let newValue = currentValue + 10;

        lumElement.innerHTML = newValue + ' <span class="shine-icon">✦</span>';

        if (newValue >= targetValue) {
            card.style.backgroundColor = '#fff9db';
            card.style.borderColor = '#ffd43b';
            card.style.transition = 'background-color 0.8s ease';
            this.textContent = 'Dream Fulfilled!';
            this.disabled = true;
            this.style.backgroundColor = '#fab005';
        }

        console.log('Luminescence increased to: ' + newValue);
    });
});

function validateForm() {
    const form = document.signup;
    const idElem = form.id;
    const nicknameElem = form.nickname;
    const emailElem = form.email;
    const titleElem = form.title;
    const lumElem = form.luminescence;
    const descElem = form.description;
    const statusElem = form.status;

    if (!/^\d{8}$/.test(idElem.value.trim())) {
        alert('Dream ID must be exactly 8 digits.');
        idElem.focus();
        return false;
    }

    const nicknameValue = nicknameElem.value.trim();
    if (nicknameValue.length < 4) {
        alert('Nickname must be at least 4 characters long.');
        nicknameElem.focus();
        return false;
    } else {
        const firstChar = nicknameValue.charAt(0).toUpperCase();
        if (firstChar < 'A' || firstChar > 'Z') {
            alert('Nickname must start with an alphabet letter.');
            nicknameElem.focus();
            return false;
        }
    }

    if (emailElem.value.trim().length === 0) {
        alert('Please enter your email address.');
        emailElem.focus();
        return false;
    }

    const titleValue = titleElem.value.trim();
    if (titleValue.length < 4) {
        alert('Dream Title must be at least 4 characters long.');
        titleElem.focus();
        return false;
    } else {
        const firstTitleChar = titleValue.charAt(0).toUpperCase();
        if (firstTitleChar < 'A' || firstTitleChar > 'Z') {
            alert('Dream Title must start with an alphabet letter.');
            titleElem.focus();
            return false;
        }
    }

    const lumValue = Number(lumElem.value);
    if (!Number.isInteger(lumValue) || lumValue <= 0 || lumValue >= 1000) {
        alert('Luminescence must be a whole number greater than 0 and less than 1000.');
        lumElem.focus();
        return false;
    }

    if (descElem.value.trim().length < 20) {
        alert('Description must be at least 20 characters.');
        descElem.focus();
        return false;
    }

    let checkedCount = 0;
    for (let i = 0; i < statusElem.length; i++) {
        if (statusElem[i].checked === true) {
            checkedCount++;
        }
    }

    if (checkedCount === 0) {
        alert('Please select at least one Dream Status.');
        if (statusElem.length > 0) {
            statusElem[0].focus();
        }
        return false;
    }

    alert('Success! Your dream has been registered');
    return true;
}




