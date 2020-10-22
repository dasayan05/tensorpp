# Problems

My code works best

```text
from anyx import *
import anyx.library as lib

with VideoRecorder("video.mp4", (512, 512), fps=60) as recorder:
    class bouncing_ball(Scene):
        circle = lib.Circle()
        
        @sync(duration=1.0)
        def drop(obj, t) -> circle:
            ...
    
    recorder << bouncing_ball
```



