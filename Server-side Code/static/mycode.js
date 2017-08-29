jQuery(document).ready(function(){
    jQuery("img").bind("click", function(){
        jQuery.post({
            url: "/",
            data: {
				dir: jQuery(this).attr("dir"),
				angle: $("#angle").val()
			},
            success: function(result) {
            }
        });
    });
	jQuery("#angle").bind("change", function(){
        jQuery.post({
            url: "/",
            data: {
				dir: 6,
				angle: $("#angle").val()
			},
            success: function(result) {
            }
        });
    });
 });
