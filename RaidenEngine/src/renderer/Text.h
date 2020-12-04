#ifndef TEXT_H
#define TEXT_H

#include <iostream>

namespace Raiden {

	class Text {
		public:
			Text(std::string text);
			~Text();
		private:
			std::string text;
	};

}

#endif
