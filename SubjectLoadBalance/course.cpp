#include "course.h"



Course::Course(std::list<Lab> labs, std::list<Lecture> lectures, std::list<Seminar> seminars):
    m_labs{labs},
    m_lectures{lectures},
    m_seminars{seminars}
{
    for(auto &lab:m_labs){
        m_freeLabs.push_back(&lab);
    }

    for(auto &lecture:m_lectures){
        m_freeLectures.push_back(&lecture);
    }

    for(auto &seminar:m_seminars){
        m_freeSeminars.push_back(&seminar);
    }
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

std::list<Lab *> Course::delegateLabs(int amount)
{


    auto end =  std::next(m_freeLabs.begin(),amount);
    std::list<Lab *> labsToDelegate{m_freeLabs.begin(),end};

    m_freeLabs.erase(m_freeLabs.begin(),end);
    return labsToDelegate;

}

std::list<Lecture *> Course::delegateLectures(int amount)
{
    auto end =  std::next(m_freeLectures.begin(),amount);
    std::list<Lecture *> lecturesToDelegate{m_freeLectures.begin(),end};

    m_freeLectures.erase(m_freeLectures.begin(),end);
    return lecturesToDelegate;

}

std::list<Seminar *> Course::delegateSeminars(int amount)
{
    auto end =  std::next(m_freeSeminars.begin(),amount);
    std::list<Seminar *> seminarsToDelegate{m_freeSeminars.begin(),end};

    m_freeSeminars.erase(m_freeSeminars.begin(),end);
    return seminarsToDelegate;

}

void Course::test()
{
    for(auto lab:m_labs){
        lab.test();
    }

    for(auto lecture:m_lectures){
        lecture.test();
    }

    for(auto seminar:m_seminars){
        seminar.test();
    }
}
