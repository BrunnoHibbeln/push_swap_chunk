*This project has been created as part of the 42 curriculum by bhibbeln.*

# Push Swap

## Description
Push_swap is a algorithmic project at 42 School. The goal is to sort a stack of integers using two stacks (`a` and `b`) and a specific set of instructions. The challenge is to sort the data with the **minimum number of operations** possible.

The program calculates and displays the smallest list of instructions to sort the integer arguments received.

**The Rules:**
* You have two stacks: `a` (initially contains the random numbers) and `b` (initially empty).
* You can only use operations like:
    * swap: `sa`, `sb`.
    * push: `pa`, `pb`.
    * rotate: `ra`, `rb`.
    * reverse-rotate: `rra`, `rrb`.

### The "Chunk" Algorithm

This project implements a range-based "Chunk" sorting algorithm, which is a simplified variation of **[Bucket Sort](https://www.geeksforgeeks.org/dsa/bucket-sort-2/)**.

* **Pre-processing:** The values in Stack A are analyzed to define value ranges or "chunks" (e.g., separating numbers into 5 groups from smallest to largest).
* **Push to B:** The algorithm scans Stack A for numbers belonging to the current chunk.
    * If a number is found, it is pushed to Stack B (`pb`).
    * **Optimization:** If the number belongs to the *bottom half* of the chunk, Stack B is rotated (`rb`). This creates a "sandglass" distribution in Stack B, keeping smaller numbers at the bottom and larger numbers near the top, which speeds up the return phase.
* **Return to A:** Once Stack A is empty (or near empty), elements are pushed back from B to A (`pa`). Since B is roughly sorted, the algorithm simply identifies the maximum value (or the "cheapest" move) in B and places it correctly onto A.

## Instructions

### Compilation
After clone the repository, to compile the project, run the following command in the terminal:
```
make
```
This will create the executable `./push_swap` that we can tested like that:
```
./push_swap 1 5 7 3

or

./push_swap "1 5 7 3"
```
The program will return the exactly operations to sort this list of numbers:
```
pb
rra
pa
```
Now, to test with a larger list, we can generate a **random** list using a **[Ruby](https://www.ruby-lang.org/en/documentation/)**, directly in the terminal:
```
ruby -e "puts (0..100).to_a.shuffle.join(' ')"
```
And then we put that into a **[bash variable](https://www.w3schools.com/bash/bash_variables.php)** to later pass this as argument to the `./push_swap`:
```
NUMBERS=$(ruby -e "puts (0..100).to_a.shuffle.join(' ')");
```
Now we can just do this `./push_swap $NUMBERS`, but this will return a **LOT** of lines. So, we can use **[bash command](https://www.w3schools.com/bash/bash_commands.php)** to filter all these lines and count them with `| wc -l`. And finally, you can make all the tests as you want 🤓.
```
NUMBERS=$(ruby -e "puts (0..100).to_a.shuffle.join(' ')"); ./push_swap $NUMBERS | wc -l
```

## Resources

### Documentation & Logic
* **Visualizer:** **[Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer)** Essential for debugging and verifying your sort visually.
* **The "Chunk" Logic:** A simplified implementation of Bucket Sort, where the stack is divided into value ranges ('chunks') to optimize the transfer of elements between stacks, minimizing the operation count.
    * *Reference:* **[Push Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)**.
    * *Reference:* **[Push Swap in less than 4200 operations](https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0)**.

* **Tutorials:** These following tutorials are amazing, even that in the end, i didn't use the **[Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)** that they used, but help me a lot to build the struct of my project.
    * **[Push Swap by Thuggonaut](https://www.youtube.com/watch?v=wRvipSG4Mmk)**.
    * **[Push Swap by Oceano](https://www.youtube.com/watch?v=OaG81sDEpVk&t)**.

### AI Usage
Artificial Intelligence (Gemini) was used as a thought partner and debugging assistant during the development of this project. Specific tasks included:
* **Debugging:** Identifying segmentation faults in edge cases (e.g., handling strings with only spaces ` "   " `) and fixing logic errors in the main validator.
* **Syntax & Norminette:** Assisting in refactoring code to adhere to strict 42 Norminette standards (reducing line counts, fixing "dangling else" issues) while ensuring the logic remained correct.
* **Testing Scripts:** Generating one-liners in Ruby and C to produce random number sets for performance testing.