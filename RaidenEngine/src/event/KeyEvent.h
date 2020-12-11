#ifndef KEY_EVENT_H
#define KEY_EVENT_H

#include "Event.h"

namespace Raiden {

	class KeyEvent : public Event {
		public:
			KeyEvent(int key) : keycode(key) {
				
			}

			static std::string getStaticEventType() {
				return "KeyEvent";
			}

			int getKey() {
				return keycode;
			}

			virtual std::string getEventType() override {
				return "KeyEvent";
			}
		private:
			int keycode;
	};

}

#endif
