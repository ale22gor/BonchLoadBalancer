#include "course.h"


Course::Course(){

}

Course::Course(std::list<std::shared_ptr<Lab> > labs, std::list<std::shared_ptr<Lecture> > lectures, std::list<std::shared_ptr<Seminar> > seminars):
    m_labs{labs},m_freeLabs{labs},
    m_lectures{lectures},m_freeLectures{lectures},
    m_seminars{seminars},m_freeSeminars{seminars}
{
    /*
    for(auto &lab:m_labs){
        m_freeLabs.push_back(&lab);
    }

    for(auto &lecture:m_lectures){
        m_freeLectures.push_back(&lecture);
    }

    for(auto &seminar:m_seminars){
        m_freeSeminars.push_back(&seminar);
    }
    */
}


bool Course::checkLabs(int amount)
{
    if(static_cast<int>(m_freeLabs.size()) >=amount)
        return true;
    else
        return false;
}

bool Course::checkLectures(  int amount)
{
    if(static_cast<int>(m_freeLectures.size()) >=amount)
        return true;
    else
        return false;
}

bool Course::checkSeminars(  int amount)
{
    if(static_cast<int>(m_freeSeminars.size()) >=amount)
        return true;
    else
        return false;
}

void Course::addLabs(std::shared_ptr<Group> group, int hours)
{
    std::shared_ptr<Lab> tmp{new Lab{group,hours}};
    m_labs.push_back(tmp);
    m_freeLabs.push_back(tmp);
}

void Course::addLecture(std::shared_ptr<Group> group, int hours)
{
    std::shared_ptr<Lecture> tmp{new Lecture{group,hours}};
    m_lectures.push_back(tmp);
    m_freeLectures.push_back(tmp);
}

void Course::addSeminar(std::shared_ptr<Group> group, int hours)
{
    std::shared_ptr<Seminar> tmp{new Seminar{group,hours}};
    m_seminars.push_back(tmp);
    m_freeSeminars.push_back(tmp);
}

std::list<std::shared_ptr<Lab> > Course::delegateLabs(int amount)
{


    auto end =  std::next(m_freeLabs.begin(),amount);
    std::list<std::shared_ptr<Lab> > labsToDelegate{m_freeLabs.begin(),end};

    m_freeLabs.erase(m_freeLabs.begin(),end);
    return labsToDelegate;

}

std::list<std::shared_ptr<Lecture> > Course::delegateLectures(int amount)
{
    auto end =  std::next(m_freeLectures.begin(),amount);
    std::list<std::shared_ptr<Lecture> > lecturesToDelegate{m_freeLectures.begin(),end};

    m_freeLectures.erase(m_freeLectures.begin(),end);
    return lecturesToDelegate;

}

std::list<std::shared_ptr<Seminar> > Course::delegateSeminars(int amount)
{
    auto end =  std::next(m_freeSeminars.begin(),amount);
    std::list<std::shared_ptr<Seminar> > seminarsToDelegate{m_freeSeminars.begin(),end};

    m_freeSeminars.erase(m_freeSeminars.begin(),end);
    return seminarsToDelegate;

}

void Course::test()
{
    for(auto lab:m_labs){
        lab->test();
    }

    for(auto lecture:m_lectures){
        lecture->test();
    }

    for(auto seminar:m_seminars){
        seminar->test();
    }
}
