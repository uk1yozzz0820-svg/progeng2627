#include <iostream>
#include <string>
#include <vector>

bool word_fits_at(const std::vector<std::string>& grid,
                  const std::string& word,
                  std::size_t start_row, std::size_t start_col,
                  std::size_t row_step, std::size_t col_step)
{
    std::size_t length = word.size();
    std::size_t rows = grid.size();
    std::size_t cols = 0;
    if (rows > 0){
        cols = grid[0].size();
    }
    std::size_t last_row = start_row + row_step * (length - 1);
    std::size_t last_col = start_col + col_step * (length - 1);
    if(last_row < rows){
        if(last_col < cols){
            return true;
        }
    }
    return false;
}

bool word_matches_at(const std::vector<std::string>& grid,
                     const std::string& word,
                     std::size_t start_row, std::size_t start_col,
                     std::size_t row_step, std::size_t col_step)
{
    bool letters_match = true;
    std::size_t i = 0;

    while (letters_match && i < word.size()){
        std::size_t row = start_row + row_step * i;
        std::size_t col = start_col + col_step * i;

        if (grid[row][col] != word[i]){
            letters_match = false;
        }

        i++;
    }

    return letters_match;
}

void write_word(std::vector<std::string>& solution,
                const std::string& word,
                std::size_t start_row, std::size_t start_col,
                std::size_t row_step, std::size_t col_step)
{
    for(std::size_t i = 0; i < word.size(); i++){
        std::size_t row = start_row + row_step * i;
        std::size_t col = start_col + col_step * i;
        solution[row][col] = word[i];
    }
}

bool search_direction(const std::vector<std::string>& grid,
                      const std::string& word,
                      std::size_t row_step, std::size_t col_step,
                      std::vector<std::string>& solution)
{
    bool found = false;
    std::size_t rows = grid.size();
    std::size_t cols = 0;
    if (rows > 0){
        cols = grid[0].size();
    }
    std::size_t row = 0;
    while(!found && row < rows){
        std::size_t col = 0;
        while(!found && col < cols){
            if (word_fits_at(grid, word, row, col, row_step, col_step) &&
                word_matches_at(grid, word, row, col, row_step, col_step)){
                found = true;
                write_word(solution, word, row, col, row_step, col_step);
            }
            col++;
        }
        row++;
    }

    return found;
}

void find_words(
    const std::vector<std::string>& grid,
    const std::vector<std::string>& words,
    std::vector<std::string>& solution,
    std::vector<std::string>& not_found
)
{
    solution.clear();
    not_found.clear();

    std::size_t rows = grid.size();
    std::size_t cols = 0;
    if (rows > 0){
        cols = grid[0].size();
    }

    for(std::size_t i = 0; i < rows; i++){
        solution.push_back(std::string(cols, '#'));
    }

    for(std::size_t i = 0; i < words.size(); i++){
        bool found = search_direction(grid, words[i], 0, 1, solution);

        if (!found){
            found = search_direction(grid, words[i], 1, 0, solution);
        }

        if (!found){
            not_found.push_back(words[i]);
        }
    }
}

void print_lines(const std::vector<std::string>& lines)
{
    for (std::size_t i = 0; i < lines.size(); i++)
    {
        std::cout << "    \"" << lines[i] << "\"" << std::endl;
    }
}

bool run_test(const std::string& test_name,
              const std::vector<std::string>& grid,
              const std::vector<std::string>& words,
              const std::vector<std::string>& expected_solution,
              const std::vector<std::string>& expected_not_found)
{
    std::vector<std::string> solution;
    std::vector<std::string> not_found;

    find_words(grid, words, solution, not_found);

    bool passed = (solution == expected_solution) &&
                  (not_found == expected_not_found);

    if (passed)
    {
        std::cout << "[test passed] " << test_name << std::endl;
    }
    else
    {
        std::cout << "[test failed] " << test_name << std::endl;
        std::cout << "  expected solution:" << std::endl;
        print_lines(expected_solution);
        std::cout << "  your solution:" << std::endl;
        print_lines(solution);
        std::cout << "  expected not_found:" << std::endl;
        print_lines(expected_not_found);
        std::cout << "  your not_found:" << std::endl;
        print_lines(not_found);
    }

    return passed;
}

int main()
{
    int tests_run = 0;
    int tests_passed = 0;

    tests_run++;
    if (run_test("official 6x7 example",
                 {"xappleg",
                  "dzeazkg",
                  "zwazzbx",
                  "dxnqzoy",
                  "qyueytp",
                  "pythtyg"},
                 {"peanut", "bot", "mango", "apple", "cinnamon"},
                 {"#apple#",
                  "##e####",
                  "##a##b#",
                  "##n##o#",
                  "##u##t#",
                  "##t####"},
                 {"mango", "cinnamon"}))
    {
        tests_passed++;
    }

    tests_run++;
    if (run_test("official single-row example",
                 {"zapplexyzwxbotyz"},
                 {"bot", "apple"},
                 {"#apple#####bot##"},
                 {}))
    {
        tests_passed++;
    }

    tests_run++;
    if (run_test("words on right and bottom edges",
                 {"abc",
                  "def",
                  "ghi"},
                 {"cfi", "ghi", "xyz"},
                 {"##c",
                  "##f",
                  "ghi"},
                 {"xyz"}))
    {
        tests_passed++;
    }

    tests_run++;
    if (run_test("words longer than the grid",
                 {"ab",
                  "cd"},
                 {"abc", "acx", "ac"},
                 {"a#",
                  "c#"},
                 {"abc", "acx"}))
    {
        tests_passed++;
    }

    tests_run++;
    if (run_test("partial match before real match",
                 {"apapple"},
                 {"apple"},
                 {"##apple"},
                 {}))
    {
        tests_passed++;
    }

    tests_run++;
    if (run_test("single column",
                 {"c",
                  "a",
                  "t",
                  "s"},
                 {"cat", "dog"},
                 {"c",
                  "a",
                  "t",
                  "#"},
                 {"dog"}))
    {
        tests_passed++;
    }

    tests_run++;
    if (run_test("no word found",
                 {"abc",
                  "def"},
                 {"zzz", "fed"},
                 {"###",
                  "###"},
                 {"zzz", "fed"}))
    {
        tests_passed++;
    }

    std::cout << std::endl << tests_passed << " / " << tests_run
              << " tests passed" << std::endl;

    return 0;
}