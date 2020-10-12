//
// Created by simon on 2020. 10. 12..
//

#ifndef MY_MATH_MY_SPECIAL_RELATIVITY_H
#define MY_MATH_MY_SPECIAL_RELATIVITY_H

#import "my_vector.h"
#import "my_matrix.h"

class Event {
    Vector4D p;
    std::string name;
public:
    Event(const Vector4D& p, const std::string& n = "event"): p(p), name(n) {}
};

class Observer {

public:
    Observer() {}
};

/**
 * An absolute representation of the Spacetime.
 *
 */
class Spacetime {
    std::vector<Event*> events;
public:
    Spacetime(): events() {}

};

#endif //MY_MATH_MY_SPECIAL_RELATIVITY_H
