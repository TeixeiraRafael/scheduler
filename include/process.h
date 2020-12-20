#ifndef PROCESS_H
#define PROCESS_H

#include "definitions.h"

class Process{

private:

    //Private Attributes
    int pid;
    string uuid;
    int memory; //Dummy datatype, this attribute will not be used yet.
    string name;
    int priority;
    int tickets;
    int duration;
    int remaining;
    bool done, running;

public:
    //Constructors and destructors
    Process(string name, int pid, int duration, int priority, string uuid, int memory); //Constructs a process from explicit parameters
    Process(string process_string); //Constructs a object from a proccess description string
    ~Process();

    // Getters
    string getName();
    int getPid();
    int getDuration();
    int getRemaining();
    int getPriority();
    string getUuid();
    int getMemory();
    bool isRunning();
    bool isDone();

    // Setters
    void setName(string name);
    void setPid(int pid);
    void setDuration(int duration);
    void setPriority(int priority);
    void setUuid(string uuid);
    void setMemory(int memory);
    void setDone();
    void setRunning(bool running);

    //Other Functions
    void info();
    void step();

};
#endif