function change()
{
	document.body.style.backgroundColor = 
	"rgb(" + Math.round(Math.random() * 255)+
	"," + Math.round(Math.random() * 255)+
	"," + Math.round(Math.random() * 255) + ")";

	var button = document.getElementById('button')
	var width1 = button.offsetWidth
	var height1 = button.offsetHeight
	button.style.height = (height1 + 5) + "px"
	button.style.width = (width1 + 5) + "px"
	size = getComputedStyle(button).getPropertyValue('font-size')
	currentsize = parseFloat(size)
	button.style.fontSize = (currentsize + 1) + "px"
}