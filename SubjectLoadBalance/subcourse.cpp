#include "subcourse.h"
#include "course.h"
#include "lab.h"
#include "lecture.h"
#include "seminar.h"



SubCourse::SubCourse(std::shared_ptr<Course> course, int labAmount,int lecturesamount, int  seminarAmount)
    :m_course{course}
{
    std::list<std::shared_ptr<AdministrativeUnit> > admUnits{m_course->m_lab->delegate(labAmount)};
    m_lab = {std::make_shared<Lab>(admUnits, m_course->m_lab->getHours()) };
    //m_labs = m_course->delegateLabs(labAmount);
    //m_lectures = m_course->delegateLectures(lecturesamount);
    //m_seminars = m_course->delegateSeminars(seminarAmount);
}

void SubCourse::test()
{
    m_lab->test();
    m_lecture->test();
    m_seminar->test();
}
