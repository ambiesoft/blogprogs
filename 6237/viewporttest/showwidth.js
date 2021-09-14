
function showwidth() {
    let text =
        `screen.width=${screen.width}
        screen.height=${screen.height}
        document.documentElement.clientWidth=${document.documentElement.clientWidth}
        document.documentElement.clientheight=${document.documentElement.clientHeight}
        window.innerWidth=${window.innerWidth}
        window.innerheight=${window.innerHeight}
`;
    document.getElementById('content').innerText = text;
}

window.setInterval(() => {
    showwidth();
}, 1000);