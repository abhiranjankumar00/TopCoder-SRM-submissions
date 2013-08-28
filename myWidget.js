$(function() {
	MY_PLUGIN_NAME = "MyPlugin";
	var content = "<a class=\"twitter-timeline\" href=\"https://twitter.com/AnupamPkher\" data-widget-id=\"370866504859799552\">Tweets by @AnupamPkher</a>";
	<script>
	!function(d,s,id){
		var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?'http':'https';
		if(!d.getElementById(id)){
			js=d.createElement(s);
			js.id=id;
			js.src=p+"://platform.twitter.com/widgets.js";
			fjs.parentNode.insertBefore(js,fjs);
		}}(document,"script","twitter-wjs");
</script>

	$("#"+MY_PLUGIN_NAME).html(content);
})
