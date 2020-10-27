import acimg from "./img/test.png"
import  './css/index.css'
console.log(acimg[0]);

let t = new Image();
t.src = acimg;
t.classList.add("img-title");
t.className = "image-title";
document.body.appendChild(t);