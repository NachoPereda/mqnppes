#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>
#include <iomanip>


std::string generate_rmqe_formula(int n, int m) {
    std::string rmqe_formula = "";

    for (int p = 1; p <= m; ++p) {
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                rmqe_formula += "p(" + std::to_string(i) + "," + std::to_string(j) + ") * x" + std::to_string(i) + " * x" + std::to_string(j) + " + ";
            }
        }

        for (int i = 1; i <= n; ++i) {
            rmqe_formula += "p(" + std::to_string(i) + ") * x" + std::to_string(i) + " + ";
        }

        rmqe_formula += "p(0)";

        if (p != m) {
            rmqe_formula += ") + ";
        }
    }

    return rmqe_formula;
}

std::vector<std::vector<std::string>> to_matrix(int n, const std::string& rmqe) {
    int filas = n + 3;
    int columnas = n * 3;
    std::vector<std::vector<std::string>> matriz(filas, std::vector<std::string>(columnas, "$"));
    int fil = 0;
    int col = 0;

    std::regex term_regex("\\s*\\+\\s*");
    std::regex factor_regex("\\s*\\*\\s*");
    std::vector<std::string> terms(std::sregex_token_iterator(rmqe.begin(), rmqe.end(), term_regex, -1), {});

    for (const std::string& term : terms) {
        std::vector<std::string> factors(std::sregex_token_iterator(term.begin(), term.end(), factor_regex, -1), {});

        for (const std::string& factor : factors) {
            if (col == columnas) {
                fil += 1;
                col = (fil == n) ? 0 : 3 * fil;
            }

            if (fil == n) {
                if ((col + 1) % 3 == 0) {
                    col += 1;
                    if (col == columnas) {
                        fil += 1;
                        col = 0;
                    }
                }
            }

            if (fil == n + 1) {
                matriz[fil][columnas - 1] = "s_k";
                matriz[fil + 1][0] = "c0";
            }

            if (fil == n + 2) {
                matriz[fil][0] = "c0";
            }

            matriz[fil][col] = factor;
            col += 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        matriz[filas - 1][((i + 1) * 3) - 1] = "c" + std::to_string(i + 1);
    }

    return matriz;
}

int main() {
    int n, m;
    std::cout << "Enter the value for n: ";
    std::cin >> n;
    std::cout << "Enter the value for m: ";
    std::cin >> m;

    std::string rmqe_formula = generate_rmqe_formula(n, m);
    std::cout << "rmqe = " << rmqe_formula << std::endl;

    auto matrix = to_matrix(n, rmqe_formula);
    std::cout << "Picture:" << std::endl;
    for (const auto& fila : matrix) {
        for (const auto& elemento : fila) {
            std::cout << std::setw(5) << elemento;
        }
        std::cout << std::endl;
    }

    return 0;
}
