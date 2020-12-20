# Scheduler

This is a reimplementation of the process scheduler task for the Operational Systems course.

The goal is to explore the implementation of a process scheduler running on a backend thread and a frontend interface 
built with ncurses consuming the data from the scheduler.

Since this is a single consumer/producer scenario I'll also try to implement a [thread-safe queue using condition variables](https://www.justsoftwaresolutions.co.uk/threading/implementing-a-thread-safe-queue-using-condition-variables.html).

I'll also be fixing a lot of bugs and unnecessary redundancies from that shameless go-horse approach I took at the time.