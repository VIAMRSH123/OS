# Daily Commit Backlog

A queue of real work for this repo. A scheduled Claude Code agent runs once a day, takes the **top
unchecked item**, does it properly, verifies it, and commits.

## Rules the daily agent follows

1. **One item per run.** Finish it or leave it uncommitted.
2. **This is submitted coursework (Tier B). Changes are ADDITIVE only.**
   - ALLOWED: READMEs, `.gitignore`, build/run notes, provenance notes, removing clearly accidental
     junk (see D1/D2 — those need VB's decision first).
   - FORBIDDEN: editing any `.c` file, changing an algorithm or its output, regenerating the
     screenshots, reformatting source, or anything that alters what was assessed. If a program looks
     wrong, record it under "Observations for VB" — never fix it silently.
3. **Verify.** Any compile/run command a README gives must be one that was actually run. Confirm no
   executable source file changed (`git diff --stat` shows only `.md`/`.gitignore`).
4. **Stage named paths only** — never `git add -A` / `git add .`.
5. Conventional commit messages; tick the item and append to the Log in the same commit.
6. No filler. If nothing honest is left, make no commit.

---

## Queue

### A. Documentation (the main value for a recruiter)

- [ ] **A1 — Fix the top-level README.** It claims "the output of each program is also attached ... as
      comments at the end of the code". Verified false: no `.c` file contains output comments;
      outputs are the `.png` screenshots next to each program (`Lab 4/Dining Philosopher` has none).
      Rewrite to say that, add a "how to build" section (`gcc file.c -o file`; `-lpthread` for Lab 4
      Dining Philosophers, `-lm` for Lab 3 Rate Monotonic which calls `pow`), and a table mapping each
      lab to its program, source path and screenshot. All 19 programs compiled cleanly with gcc on
      Linux during the audit (only two unused-variable warnings, `Lab 7/FIFO` and `Lab 7/LRU`).
- [ ] **A2 — Per-lab READMEs** (`Lab 1/README.md` ... `Lab 7/README.md`): the problem each program
      solves, the input it prompts for (read from the source, then run it with sample input), the
      output format, and a link to its screenshot. Do one lab per run.
- [ ] **A3 — Document `OS Lab CIE/`**: the CIE program is a First Fit memory allocator (same
      structure as `Lab 6/FirstFit`); say what it takes as input and link `Lab exam output.png`.
- [ ] **A4 — Note the Dining Philosophers needs POSIX** (`pthread.h`, `semaphore.h`, `unistd.h`) and
      will not build with MSVC/MinGW without a pthread layer; document how to run it on Linux/macOS/WSL.
- [ ] **A5 — Note about `OS Lab report(WA039).pdf`** (21 MB): describe in the README what it
      contains (open and read it first; do not guess), so the index is accurate.

### B. Repo hygiene (additive)

- [ ] **B1 — Add `.gitignore`**: compiled binaries (`*.exe`, `*.out`, `a.out`), `.vscode/`,
      `.DS_Store`. This only affects *future* files; it does not remove tracked ones (see D1/D2).

### D. Needs VB's decision (agent must not do these on its own)

- [ ] **D1 — Tracked Windows binaries** `Lab 4/Producer Consumer/ProducerConsumer.exe` (PE32+ x64) and
      `Lab 5/Bankers/Bankers.exe` (PE32 i386) are committed build artifacts. Removing them is allowed
      by the Tier B rules (accidental junk) but they were part of the submission — VB to confirm.
- [ ] **D2 — Tracked `.vscode/` folder** (C/C++ Runner settings, launch.json). Editor config, likely
      removable; VB to confirm.

## Observations for VB (do not fix — graded work)

- `Lab 7/FIFO/FIFO.c` and `Lab 7/LRU/LRU.c` declare an unused variable `k` (compiler warning only).
- The report PDF is 21 MB and is tracked in git history, which makes clones heavy.
- Git repository is detached-HEAD at `main` in the working clone; origin is `VIAMRSH123/OS`.

## Log

2026-10-22 - audit - docs: add COMMIT_BACKLOG.md audit of OS lab repo
