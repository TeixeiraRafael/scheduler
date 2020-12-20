#include "process.h"

Process::~Process(){};

Process::Process(string process_string){
    string remainder = process_string;

    int end = remainder.find("|");
    string name = remainder.substr(0, end);
    remainder = remainder.substr(end + 1, remainder.size() - 1);

    end = remainder.find("|");
    int pid = stoi(remainder.substr(0, end));
    remainder = remainder.substr(end + 1, remainder.size() - 1);

    end = remainder.find("|");
    int duration = stoi(remainder.substr(0, end));
    remainder = remainder.substr(end + 1, remainder.size() - 1);

    end = remainder.find("|");
    int priority = stoi(remainder.substr(0, end));
    remainder = remainder.substr(end + 1, remainder.size() - 1);

    end = remainder.find("|");
    string uuid = remainder.substr(0, end);
    remainder = remainder.substr(end + 1, remainder.size() - 1);

    int memory = stoi(remainder);

    this->name = name;
    this->pid = pid;
    this->duration = duration;
    this->remaining = duration;
    this->priority = priority;
    this->uuid = uuid;
    this->memory = memory;
    this->done = false;
    this->running = false;
};

Process::Process(string name, int pid, int duration, int priority, string uuid, int memory = 0){
    this->name = name;
    this->pid = pid;
    this->duration = duration;
    this->remaining = duration;
    this->priority = priority;
    this->uuid = uuid;
    this->memory = memory;
    this->done = false;
    this->running = false;
}

string Process::getName(){
    return this->name;
}

int Process::getPid(){
    return this->pid;
}

int Process::getDuration(){
    return this->duration;
}

int Process::getRemaining(){
    return this->remaining;
}

int Process::getPriority(){
    return this->priority;
}

string Process::getUuid(){
    return this->uuid;
}

int Process::getMemory(){
    return this->memory;
}

bool Process::isRunning(){
    return this->running;
}

void Process::setName(string name){
    this->name = name;
}

void Process::setPid(int pid){
    this->pid = pid;
}

void Process::setDuration(int duration){
    this->duration = duration;
}

void Process::setPriority(int priority){
    this->priority = priority;
}

void Process::setUuid(string uuid){
    this->uuid = uuid;
}

void Process::setMemory(int memory){
    this->memory = memory;
}

void Process::setRunning(bool running){
    this->running = running;
}

void Process::info(){
    /*
    cout << endl << "Proccess " << this->pid << " info: " << endl;
    cout << "\tName: " << this->name << endl;
    cout << "\tPID: " << this->pid << endl;
    cout << "\tPriority: " << this->priority << endl;
    cout << "\tUUID: " << this->uuid << endl;
    cout << "\tMemory: " << this->memory << endl << endl;
    */
    cout << name << "(" << priority << ")" << "\t\t\t" << duration << " cicles, " << remaining  << " remaining."<< endl;
}

void Process::setDone(){
    this->done = true;
}

bool Process::isDone(){
    if(this->remaining == 0)
        return true;
    return false;
}

void Process::step(){
    if(this->remaining <= 0){
        this->done = true;
    }else{
        --this->remaining;
    }
}