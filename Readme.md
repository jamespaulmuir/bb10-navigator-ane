## BlackBerry 10 Adobe Native Extension for Navigator

This is an initial proof of concept and can be used as an example of how to create native extensions for BB10.

### This project includes:
* Native C Adobe Native Extension source code that interfaces with [navigator](https://bdsc.webapps.blackberry.com/native/reference/com.qnx.doc.bps.lib_ref/com.qnx.doc.bps.lib_ref/topic/about_navigator_8h.html)
* Actionscript library source code
* Sample Adobe Air Mobile Application that shows the usage 

### Included functionality

    import com.jamespaulmuir.bb10.Navigator;
    import com.jamespaulmuir.bb10.NavigatorBadge;
 
    // Set the badge on the Application Icon and Application Window icon
    Navigator.setBadge(NavigatorBadge.NAVIGATOR_BADGE_SPLAT);

    // Clear the badge 
    Navigator.clearBadge(); 
