document.addEventListener('DOMContentLoaded', () => {
    const toggleThemeBtn = document.getElementById('toggleThemeBtn');
    const bodyElement = document.body; //Referência direta ao elemento body

    toggleThemeBtn.addEventListener('click', () => {
        //Alterna a classe 'dark-mode' no elemento body
        bodyElement.classList.toggle('dark-mode');

        if (bodyElement.classList.contains('dark-mode')) {
            toggleThemeBtn.textContent = 'Mudar para Tema Claro';
        } else {
            toggleThemeBtn.textContent = 'Mudar para Tema Escuro';
        }
    });
});