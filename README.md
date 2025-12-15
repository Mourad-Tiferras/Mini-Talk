# System Programming Project:  Minitalk

```
			███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗██╗			
			██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝			 
			██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗			 
			██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗			
			╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝			

				PID: 0000			By:  Mourad Ph4nt0m
			⊱ ────────────────────── {.⋅ ✯ ⋅.} ─────────────────────── ⊰	

```

> 💡 _“Minitalk teaches you how two processes can talk to each other without sockets — only with pure signals!”_

---

## 🧠 About

The purpose of this project is to code a small data exchange program using **UNIX signals**.

You will create a **client-server communication system** in C:

- The **server** runs first and displays its **PID**.  
- The **client** takes the server PID and a string as arguments.  
- The client sends the string to the server **bit by bit** using `SIGUSR1` and `SIGUSR2`.  
- The server receives the message and displays it.

---

## 🧩 Table of Contents

1. [Unix Processes](#unix-processes)
2. [Unix Signals](#unix-signals)
3. [Used Functions](#used-functions)
4. [How Minitalk Works](#minitalk-explained)
5. [Project Requirements](#project-requirements)
6. [Allowed Functions](#allowed-functions)

---

## Unix Processes

Minitalk uses two separate processes that communicate via signals:
- **Server Process**: waits for messages and reconstructs data.
- **Client Process**: encodes a message and sends it via signals.

---

## Unix Signals

Signals are asynchronous notifications sent to a process to notify it of an event.  
Here we use:
- `SIGUSR1` → represents binary `1`
- `SIGUSR2` → represents binary `0`

---

## Used Functions

| Function | Description |
|-----------|--------------|
| `signal()` | Sets up a signal handler for a specific signal. |
| `sigaction()` | Provides advanced control over signal handling. |
| `struct sigaction` | Structure used with `sigaction()` to specify handlers. |
| `sigemptyset()` | Initializes a signal set to exclude all signals. |
| `sigaddset()` | Adds a specific signal to a signal set. |
| `getpid()` | Returns the current process ID (PID). |
| `kill()` | Sends a signal to a process. |
| `pause()` | Suspends process until a signal is received. |
| `sleep()` / `usleep()` | Suspends execution for a given time (useful for synchronization). |

---

## Minitalk Explained

### Step 1
**Convert each ASCII characters to binary representation.**

### Step 2
**Send binary representation of each charachter via Unix Signals to the server PID .**

### Step 3
**Convert binary representation back to ASCII characters.**

### Step 4
**Print the client msg.**

---

## Project Requirements

### About
The project tests your understanding of **signals**, **processes**, and **synchronous communication**.

Keep in mind:
- Handle errors carefully — your program **must not crash**.
- Avoid **memory leaks**.
- You can use **one global variable**, but only if **justified**.

### 🧱 Mandatory Part
- Produce two executables: `server` and `client`.
- `client` must send a string (passed as argument) to `server` (identified by PID).
- Use **only `SIGUSR1` and `SIGUSR2`** for communication.

---

## Allowed Functions

| Function | Purpose |
|-----------|----------|
| `write()` | For output. |
| `ft_printf()` *(or your own equivalent)* | For formatted output. |
| `signal()` | Signal handling. |
| `sigemptyset()`, `sigaddset()` | Signal set manipulation. |
| `sigaction()` | Advanced signal handling. |
| `kill()` | Send a signal to a process. |
| `getpid()` | Get current process PID. |
| `malloc()`, `free()` | Memory management. |
| `pause()` | Wait for a signal. |
| `sleep()`, `usleep()` | Delay execution. |
| `exit()` | Terminate process safely. |

---



> 💡 _“Minitalk teaches you how two processes can talk to each other without sockets — only with pure signals!”_


