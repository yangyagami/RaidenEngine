#ifndef EVENT_H
#define EVENT_H

#include <iostream>

namespace Raiden {

	class Event {
		public:
			virtual std::string getEventType() = 0;
			virtual ~Event() = default;
	};

	class EventDispatcher {
		public:
			EventDispatcher(Event &e) : event(e) {

			}

			template<typename T, typename F>
			void dispatch(const F &func) {
				if (event.getEventType() == T::getStaticEventType()) {
					func(static_cast<T&>(event));
				}
			}

			~EventDispatcher() {

			}
		private:
			Event &event;
	};

}

#endif
