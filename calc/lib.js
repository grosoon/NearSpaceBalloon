/*
 * JS LIBRARY
 * CORY McCARTAN
 * AUGUST 2015
 */

// call main()
document.addEventListener("readystatechange", function() {
	if (document.readyState === "complete") main();
});

// DOM getters
window.$ = function(s) { return document.querySelector(s); };
window.$$ = function(s) { return document.querySelectorAll(s); };

// utility functions
window.NULLF = function() { };
window.LOGF = function(l) { console.log(l); };

/**
 * Load a file via XMLHttpRequest
 *
 * You can pass an object, or a url + callback.  If passing an object, use the
 * following format:
 *
 * url: (required) The path to the file to load.
 * onload: the callback function when the file is loaded
 * type: the type of the file (e.g. 'blob', 'arraybuffer'.  Default is plain
 * 		text.
 * method: 'GET' or 'POST.'  Default is 'GET.'
 */
function xhr(arg1, arg2) {
	var url = "";
	var callback = NULLF;
	var type = "";
	var method = "GET";

	var request = new XMLHttpRequest();
	
	if (typeof arg1 === "object") {
		url = arg1.url;
		callback = arg1.onload || callback;
		type = arg1.type || type;
		method = arg1.method || method;
	} else {
		url = arg1;
		callback = arg2;
	}

	request.onload = function(e) {
		if (request.readyState === 4) {
			callback(request.response);
	 	}
	};

	request.open(method, url, true);
	request.responseType = type;
	request.send();
}
