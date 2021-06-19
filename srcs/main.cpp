#include "Webserv.hpp"

void DUMP(const std::list<Server> &server_list) {
	for (auto i : server_list) {
		std::cout << "Server id: " << i.server_id << std::endl;
		std::cout << "Client max body size: " << i.client_max_body_size << std::endl;
		std::cout << "Index: " << std::endl;
		for (auto j : i.index) {
			std::cout << "\t" << j << std::endl;
		}
		std::cout << "Server name: " << std::endl;
		for (auto j : i.server_name) {
			std::cout << "\t" << j << std::endl;
		}
		std::cout << "IP/PORT: " << i.listen.ip << ":" << i.listen.port << std::endl;
		std::cout << "Root: " << i.root << std::endl;
		std::cout << "Autoindex: " << i.autoindex << std::endl;
		std::cout << "Fast CGI param: " << std::endl;
		for (auto j : i.fastcgi_param) {
			std::cout << "\t" << j.first << ":" << j.second << std::endl;
		}
		std::cout << "Error page: " << std::endl;
		for (auto j : i.error_page) {
			std::cout << "\t" << j.first << ":" << j.second << std::endl;
		}
		std::cout << "Location: " << std::endl;
		for (auto j : i.location) {
			std::cout << "\t" << "Client max body size: " << j.client_max_body_size << std::endl;
			std::cout << "\t" << "Index: " << std::endl;
			for (auto k : j.index) {
				std::cout << "\t" << k << std::endl;
			}
			std::cout << "\t" << "Methods: " << std::endl;
			for (auto k : j.methods) {
				std::cout << "\t" << k << std::endl;
			}
			std::cout << "\t" << "Root: " << j.root << std::endl;
			std::cout << "\t" << "Route: " << j.route << std::endl;
			std::cout << "\t" << "Autoindex: " << j.autoindex << std::endl;
			std::cout << "\t" << "Fast CGI pass: " << j.fastcgi_pass << std::endl;
			std::cout << "\t" << "Fast CGI param: " << std::endl;
			for (auto k : j.fastcgi_param) {
				std::cout << "\t" << k.first << ":" << k.second << std::endl;
			}
			std::cout << "\t" << "Error page: " << std::endl;
			for (auto k : j.error_page) {
				std::cout << "\t" << k.first << ":" << k.second << std::endl;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}

int main(int argc, char **argv) {
	std::list<Server> server_list;
	if (parse_input(argc, argv)) {
		try {
			server_list = parse_conf(argv[1], server_list);
			DUMP(server_list);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return (1);
		}
	}
	return 0;
}
