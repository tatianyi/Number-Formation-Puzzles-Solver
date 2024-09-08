#include "bits/stdc++.h"

//const std::string ops{ "+-*/" };

void solve() {
	std::array<std::array<long double, 3>, 3> num;
	for (int i = 0; i < 3; i++) {
		std::string buf;
		for (int j = 0; j < 3; j++) {
			std::cin >> buf;
			num[i][j] = std::stold(buf);
		}
	}
	std::array<std::set<long double>, 3> res;
	for (int i = 0; i < 3; i++) {
		auto curr = num[i];
		do {
			for (size_t s1 = 0; s1 < 5; s1++) {
				std::set<long double> res01;
				switch (s1) {
				case 0:
					res01.insert(curr[0] + curr[1]);
					break;
				case 1:
					res01.insert(curr[0] - curr[1]);
					res01.insert(curr[1] - curr[0]);
					break;
				case 2:
					res01.insert(curr[0] * curr[1]);
					break;
				case 3:
					res01.insert(curr[0] / curr[1]);
					res01.insert(curr[1] / curr[0]);
					break;
				default:
					res01.insert(std::powl(curr[0], curr[1]));
					res01.insert(std::powl(curr[1], curr[0]));
					break;
				}
				for (size_t s2 = 0; s2 < 5; s2++) {
					for (auto& x : res01) {
						switch (s2) {
						case 0:
							res[i].insert(x + curr[2]);
							break;
						case 1:
							res[i].insert(x - curr[2]);
							res[i].insert(curr[2] - x);
							break;
						case 2:
							res[i].insert(x * curr[2]);
							break;
						case 3:
							res[i].insert(x / curr[2]);
							res[i].insert(curr[2] / x);
							break;
						default:
							res[i].insert(std::powl(x, curr[2]));
							res[i].insert(std::powl(curr[2], x));
							break;
						}
					}
				}
			}
		} while (std::ranges::next_permutation(curr).found);
	}
	/*for (auto& s : res) {
		std::cout << "set:\n";
		for (auto& i : s) {
			std::cout << i << ' ';
		}
		std::cout << "\n\n";
	}*/
	for (auto& s : res) {
		s.erase(std::numeric_limits<long double>::infinity());
		std::cerr << "set=\n";
		for (auto& x : s) {
			std::cerr << x << ' ';
		}
		std::cerr << "\n\n";
	}
	std::vector<long double> tmp_ans{}, true_ans{};
	std::ranges::set_intersection(res[0], res[1], std::back_inserter(tmp_ans));
	std::ranges::set_intersection(res[2], tmp_ans, std::back_inserter(true_ans));
	std::cerr << true_ans.size() << '\n';
	for (auto& e : true_ans) {
		std::cout << e << ' ';
	}
	std::cout << '\n';
}

int main() {
	std::cout.tie(nullptr)->sync_with_stdio(false);
	unsigned t = 1;
	//std::cin >> t;
	for (unsigned c = 0; c < t; c++) {
		solve();
	}
}
