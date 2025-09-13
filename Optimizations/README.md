# Optimizations
## Capping the Game Loop
The engine is still in a very basic state, so there is no multi-threading or anything like that. Instead we are just looking very simply at how we can limit how much work we do to use less CPU power.

I have measured the FPS using `std::chrono::steady_clock` and the CPU usage using System Monitor (KSysGuard).

### Uncapped
GLFW actually implements VSync by default, which caps the FPS at 60 (Because my monitor updates at 60HZ). This can be turned off using `glfwSwapInterval(0)`. 
With it turned off we can see how the program runs exactly the same as it would without (except it might produce screen tears if we rendered dynamic stuff), but it also consumes a lot more resources.

On my machine I get about 900 FPS and the CPU usage is about 12%.

![Uncapped](Optimizations/LoopPerformance_Uncapped.jpg)

### Capped by V-Sync
I'm not sure exactly how GLFW implements V-Sync, but it does seem to involve some form of sleep, since it caps my FPS at 60 and the CPU usage goes down as much as it does when I call sleep.
I did try to run the program using a busy wait just to be sure and, sure enough, with the busy-wait the CPU usage stays high, so it has to be putting the thread to sleep to get those results.

On my machine I get 60 FPS and the CPU usage is about 1%.

![Capped by V-Sync](Optimizations/LoopPerformance_CappedByVSync.jpg)

### Capped by Sleep
I added a function that would cap the fps and put the thread to sleep if it updated faster. It's pretty simple definitely shouldn't be used in an actual product. I could cap it at 60 FPS to get the same results as with V-Sync. 
This can be pretty useful though, for example if you want to make a casual game that only needs about 30 FPS, it would make a lot of sense to cap it there to avoid using unecessary resources and potentially draining a laptops battery more than necessary.
To be production ready it would need a few more things though. If a frame is slower than the cap, it should skip that frame. 
Another thing to note is that sleep is not very accurate, so we might need to [use OS-specific sleep functions or find a library that implements precise sleep](https://stackoverflow.com/a/41862592).

On my machine I get 30 FPS and the CPU usage is about 0.5%

![Capped by V-Sync](Optimizations/LoopPerformance_CappedBySleep.jpg)

### Conclusion
I think for now I will simply go with V-Sync, since that gets the CPU usage down and works well out-of-the-box with GLFW. In the future it might make sense to take another look and try to implement multi-threading and precise sleep.
