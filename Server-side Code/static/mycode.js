jQuery(document).ready(function(){
    jQuery("img").bind("click", function(){
        jQuery.post({
            url: "/",
            data: {dir: jQuery(this).attr("dir")},
            success: function(result) {
            }
        });
    });
 });

