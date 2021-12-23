const navSlide = () => {
    const menu = document.querySelector('.menu');
    const nav = document.querySelector('.nav_liste');
    menu.addEventListener('click' , () => {
    nav.classList.toggle('nav-active');
    });
}
navSlide();
