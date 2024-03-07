#ifndef _ISUBJECT_H_
#define _ISUBJECT_H_

#include "IObserver.h"

#include <memory>

class ISubject {
public:
	ISubject() = default;
	virtual ~ISubject() noexcept {}
	virtual void subscribe(std::unique_ptr<IObserver> observer) = 0;
private:
	virtual void notify() = 0;
};

#endif 