#ifndef __MAIN51MESSAGECALLBACK_H_
#define __MAIN51MESSAGECALLBACK_H_

#include "communication/message/callback/include/messagecallback.h"
#include "communication/message/include/main51message.h"
#include "communication/message/filter/include/main51messagefilter.h"
#include <memory>

namespace icsneo {

class Main51MessageCallback : public MessageCallback {
public:
	Main51MessageCallback(fn_messageCallback cb, Main51MessageFilter f = Main51MessageFilter()) : MessageCallback(cb, std::make_shared<Main51MessageFilter>(f)) {}

	// Allow the filter to be placed first if the user wants (maybe in the case of a lambda)
	Main51MessageCallback(Main51MessageFilter f, fn_messageCallback cb) : MessageCallback(cb, std::make_shared<Main51MessageFilter>(f)) {}
};

};

#endif