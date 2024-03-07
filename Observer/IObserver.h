#ifndef _IOBSERVER_H_
#define _IOBSERVER_H_

class IObserver {
public:
	IObserver() = default;
	virtual ~IObserver() noexcept {}
	virtual void handleEvent() = 0;
};

#endif 