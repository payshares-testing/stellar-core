#ifndef __PEERDOOR__
#define __PEERDOOR__

#include <boost/asio.hpp>
#include <memory>

/*
listens for peer connections.
When found passes them to the PeerMaster
*/

using namespace std;

namespace stellar
{
    class Application;
    typedef std::shared_ptr<Application> ApplicationPtr;

	class PeerDoor
	{
        ApplicationPtr mApp;

		boost::asio::ip::tcp::acceptor* mAcceptor;

		void acceptNextPeer();
		void handleKnock(shared_ptr<boost::asio::ip::tcp::socket> pSocket);
	public:
		PeerDoor();

		void start(ApplicationPtr app);
		void close();

	};
}

#endif