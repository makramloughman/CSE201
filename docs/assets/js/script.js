var cat = document.getElementsByClassName('octo-arm')[0];
window.addEventListener("load", showPage);
function showPage() {
  cat.classList.remove('js-loading');
  cat.classList.add('js-loaded');
}
