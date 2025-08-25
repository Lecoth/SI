document.addEventListener('DOMContentLoaded', () => {
    const paragrafo = document.getElementById('paragrafoEsc');
    const toggleButton = document.getElementById('toggleBtn');

    toggleButton.addEventListener('click', () => {
        const estiloAtual = window.getComputedStyle(paragrafo).display;
        if (estiloAtual === 'none') {
            paragrafo.style.display = 'block'; //Mostra
        } else {
            paragrafo.style.display = 'none'; //Esconde
        }
    });
});