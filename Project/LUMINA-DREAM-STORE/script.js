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
  const errorPanel = document.getElementById('error-output');
  const idValue = document.getElementById('id').value;
  const nicknameValue = document.getElementById('nickname').value.trim();
  const descValue = document.getElementById('description').value.trim();

  errorPanel.innerHTML = '';
  let errors = [];

  if (!/^\d{8}$/.test(idValue)) {
    errors.push('Dream ID must be exactly 8 digits.');
  }

  if (nicknameValue.length < 4) {
    errors.push('Nickname must be at least 4 characters long.');
  } else {
    const firstChar = nicknameValue.charAt(0);
    const isAlpha =
      (firstChar >= 'a' && firstChar <= 'z') || (firstChar >= 'A' && firstChar <= 'Z');
    if (!isAlpha) {
      errors.push('Nickname must start with an alphabet letter.');
    }
  }

  if (descValue.length < 20) {
    errors.push('Description must be at least 20 characters.');
  }

  if (errors.length > 0) {
    errorPanel.style.color = 'red';
    errorPanel.innerHTML = '<ul><li>' + errors.join('</li><li>') + '</li></ul>';
    return false;
  }

  const checkedStatus = document.querySelectorAll('input[name="status"]:checked');
  if (checkedStatus.length === 0) {
    errors.push('Please select at least one Dream Status.');
  }

  if (errors.length > 0) {
    errorPanel.style.color = 'red';
    errorPanel.innerHTML = '<ul><li>' + errors.join('</li><li>') + '</li></ul>';
    return false;
  }

  alert('Success! Your dream has been registered');
  return true;
}
