Operating System Lab Programs
=============================

C implementations of core operating-system algorithms, organised by lab session. Each program is a
single, self-contained `.c` file that reads its input from the terminal.

Lab contents
------------

| Lab | Topic | Program | Source | Output screenshot |
|---|---|---|---|---|
| 1 | CPU scheduling | FCFS | `Lab 1/FCFS/FCFS.c` | `Lab 1/FCFS/FCFS.png` |
| 1 | CPU scheduling | SJF (non pre-emptive) | `Lab 1/SJF/SJF(Non Pre-emptive).c` | `Lab 1/SJF/Non Pre-emptive.png` |
| 1 | CPU scheduling | SJF (pre-emptive) | `Lab 1/SJF/SJF(Pre-emptive).c` | `Lab 1/SJF/Pre emptive.png` |
| 2 | CPU scheduling | Priority Scheduling | `Lab 2/PriorityScheduling/Priority Scheduling.c` | `Lab 2/PriorityScheduling/Priority.png` |
| 2 | CPU scheduling | Round Robin | `Lab 2/RoundRobin/RoundRobin.c` | `Lab 2/RoundRobin/RoundRobin.png` |
| 3 | Real-time / multi-level | Earliest Deadline First | `Lab 3/EarliestDeadline/EarliestDeadline.c` | `Lab 3/EarliestDeadline/EarliestDeadline.png` |
| 3 | Real-time / multi-level | Rate Monotonic | `Lab 3/RateMonotonic/RateMonotonic.c` | `Lab 3/RateMonotonic/RateMonotonic.png` |
| 3 | Real-time / multi-level | Multi-Level Queue | `Lab 3/MultiLevelQueue/MultiLevelQueue.c` | `Lab 3/MultiLevelQueue/MultiLevelQueue.png` |
| 4 | Synchronisation | Dining Philosophers | `Lab 4/Dining Philosopher/DiningPhilosopher.c` | none in repo |
| 4 | Synchronisation | Producer-Consumer | `Lab 4/Producer Consumer/ProducerConsumer.c` | `Lab 4/Producer Consumer/ProducerConsumer.png` |
| 5 | Deadlock | Banker's Algorithm | `Lab 5/Bankers/Bankers.c` | `Lab 5/Bankers/Bankers.png` |
| 5 | Deadlock | Deadlock Detection | `Lab 5/Deadlock Detection/DeadlockD.c` | `Lab 5/Deadlock Detection/DeadlockD.png` |
| 6 | Memory management | Best Fit | `Lab 6/BestFit/BestFit.c` | `Lab 6/BestFit/Bestfit.png` |
| 6 | Memory management | First Fit | `Lab 6/FirstFit/FirstFit.c` | `Lab 6/FirstFit/Firstfit.png` |
| 6 | Memory management | Worst Fit | `Lab 6/WorstFit/WorstFit.c` | `Lab 6/WorstFit/Worstfit.png` |
| 7 | Page replacement | Optimal | `Lab 7/Optimal/optimal.c` | `Lab 7/Optimal/optimal.png` |
| 7 | Page replacement | FIFO | `Lab 7/FIFO/FIFO.c` | `Lab 7/FIFO/FIFO.png` |
| 7 | Page replacement | LRU | `Lab 7/LRU/LRU.c` | `Lab 7/LRU/LRU.png` |
| CIE | Lab exam | First Fit memory allocation | `OS Lab CIE/OS Lab CIE.c` | `OS Lab CIE/Lab exam output.png` |

The lab report is `OS Lab report(WA039).pdf` in the repository root.

Building and running
--------------------

Every program compiles with `gcc` on Linux (all 19 `.c` files were compiled and linked successfully):

```bash
gcc "Lab 1/FCFS/FCFS.c" -o fcfs && ./fcfs
```

Two programs need extra link flags:

- **Rate Monotonic** (`Lab 3`) calls `pow`, so link the maths library:
  `gcc "Lab 3/RateMonotonic/RateMonotonic.c" -o rm -lm`
- **Dining Philosophers** (`Lab 4`) uses POSIX threads and semaphores (`pthread.h`, `semaphore.h`,
  `unistd.h`): `gcc "Lab 4/Dining Philosopher/DiningPhilosopher.c" -o dp -lpthread`.
  Modern glibc links pthreads by default, but `-lpthread` keeps it portable. It needs a POSIX
  system (Linux, macOS, or WSL).

Quote paths: several folder and file names contain spaces or parentheses.

Output
------

The programs do not contain their output as comments. The sample output for each program is the
screenshot (`.png`) stored next to it, as listed in the table above. `Lab 4/Dining Philosopher` has no
screenshot.

Language
--------
All programs are written in C.
