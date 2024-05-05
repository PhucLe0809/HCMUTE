#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>
#include <cstring>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int ARRAY_SIZE = 200;
const int NUM_GRADIENT_COLORS = 5;  // Số lượng màu gradient từ lạnh đến nóng
const float FRAME_DELAY = 0.001f;

// Định nghĩa màu cho các cột
enum ColumnColor {
    Blue = 0,
    Purple = 1,
    Pink = 2,
    Red = 3,
    Orange = 4,
    Yellow = 5,
    Green = 6,
    SkyBlue = 7
};

// Chuyển đổi giá trị từ dãy [0, ARRAY_SIZE] thành gradient màu từ lạnh đến nóng
sf::Color gradientColor(int value) {
    int numColorSegments = NUM_GRADIENT_COLORS - 1;
    int segmentSize = ARRAY_SIZE / numColorSegments;
    int segmentIndex = value / segmentSize;

    int r = 0;
    int g = 0;
    int b = 0;

    // Tính toán màu gradient dựa trên từng phân đoạn màu
    switch (segmentIndex) {
        case 0:
            r = 0;
            g = value * (255 / segmentSize);
            b = 255;
            break;
        case 1:
            r = 0;
            g = 255;
            b = 255 - ((value - segmentSize) * (255 / segmentSize));
            break;
        case 2:
            r = (value - 2 * segmentSize) * (255 / segmentSize);
            g = 255;
            b = 0;
            break;
        case 3:
            r = 255;
            g = 255 - ((value - 3 * segmentSize) * (255 / segmentSize));
            b = 0;
            break;
        case 4:
            r = 255;
            g = 0;
            b = (value - 4 * segmentSize) * (255 / segmentSize);
            break;
        default:
            break;
    }

    return sf::Color(r, g, b);
}

void bubbleSort(std::vector<std::pair<int, int>>& temp, std::vector<sf::RectangleShape>& columns, std::vector<ColumnColor>& columnColors, sf::Sound& swapSound, sf::RenderWindow& window, sf::Font& font) {
    int n = temp.size();
    int comparisons = 0;
    int swaps = 0;
    std::vector<int> arr;
    for (auto& it : temp) arr.push_back(it.first);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                std::swap(columns[j], columns[j + 1]);
                std::swap(columnColors[j], columnColors[j + 1]); // Sắp xếp mảng màu tương ứng
                swaps++;
                swapSound.play();

                window.clear();

                for (int k = 0; k < ARRAY_SIZE; k++) {
                    columns[k].setPosition(static_cast<float>(k * 4), WINDOW_HEIGHT - columns[k].getSize().y);
                    columns[k].setFillColor(gradientColor(k));
                    columns[k].setOutlineColor(sf::Color::Black); // Đặt màu viền đen cho cột
                    columns[k].setOutlineThickness(1);

                    window.draw(columns[k]);
                }

                // Hiển thị task vụ bên trái với kích thước font 18
                sf::Text algorithmName("Algorithm: Bubble Sort", font, 18);
                sf::Text arraySize("Number of elements: " + std::to_string(ARRAY_SIZE), font, 18);
                sf::Text sortedRatio("Sorted ratio: " + std::to_string(static_cast<double>(swaps) / (ARRAY_SIZE - 1)), font, 18);
                sf::Text comparisonsText("Comparisons performed: " + std::to_string(comparisons), font, 18);
                sf::Text swapsText("Swaps performed: " + std::to_string(swaps), font, 18);

                algorithmName.setPosition(10, 10);
                arraySize.setPosition(10, 40);
                sortedRatio.setPosition(10, 70);
                comparisonsText.setPosition(10, 100);
                swapsText.setPosition(10, 130);

                window.draw(algorithmName);
                window.draw(arraySize);
                window.draw(sortedRatio);
                window.draw(comparisonsText);
                window.draw(swapsText);

                window.display();

                sf::sleep(sf::seconds(FRAME_DELAY));
            }
        }
    }
    for (int k = 0; k < n; k++) {
        swapSound.play();
        window.clear();

        for (int k = 0; k < ARRAY_SIZE; k++) {
            columns[k].setPosition(static_cast<float>(k * 4), WINDOW_HEIGHT - columns[k].getSize().y);
            columns[k].setFillColor(gradientColor(k));
            columns[k].setOutlineColor(sf::Color::Black); // Đặt màu viền đen cho cột
            columns[k].setOutlineThickness(1);

            window.draw(columns[k]);
        }

        columns[k].setPosition(static_cast<float>(k * 4), WINDOW_HEIGHT - columns[k].getSize().y);
        columns[k].setFillColor(sf::Color::White);
        columns[k].setOutlineColor(sf::Color::Black); // Đặt màu viền đen cho cột
        columns[k].setOutlineThickness(1);
        window.draw(columns[k]);

        sf::sleep(sf::seconds(0.001f));

        // Hiển thị task vụ bên trái với kích thước font 18
        sf::Text algorithmName("Algorithm: Bubble Sort", font, 18);
        sf::Text arraySize("Number of elements: " + std::to_string(ARRAY_SIZE), font, 18);
        sf::Text sortedRatio("Sorted ratio: " + std::to_string(static_cast<double>(swaps) / (ARRAY_SIZE - 1)), font, 18);
        sf::Text comparisonsText("Comparisons performed: " + std::to_string(comparisons), font, 18);
        sf::Text swapsText("Swaps performed: " + std::to_string(swaps), font, 18);

        algorithmName.setPosition(10, 10);
        arraySize.setPosition(10, 40);
        sortedRatio.setPosition(10, 70);
        comparisonsText.setPosition(10, 100);
        swapsText.setPosition(10, 130);

        window.draw(algorithmName);
        window.draw(arraySize);
        window.draw(sortedRatio);
        window.draw(comparisonsText);
        window.draw(swapsText);

        window.display();

        sf::sleep(sf::seconds(0.01f));
    }
}

void insertionSort(std::vector<std::pair<int, int>>& temp, std::vector<sf::RectangleShape>& columns, std::vector<ColumnColor>& columnColors, sf::Sound& swapSound, sf::RenderWindow& window, sf::Font& font) {
    int n = temp.size();
    int comparisons = 0;
    int swaps = 0;
    std::vector<int> arr;
    for (auto& it : temp) arr.push_back(it.first);

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            std::swap(columns[j + 1], columns[j]);
            std::swap(columnColors[j + 1], columnColors[j]); // Sắp xếp mảng màu tương ứng
            swaps++;
            swapSound.play();

            window.clear();

            for (int k = 0; k < ARRAY_SIZE; k++) {
                columns[k].setPosition(static_cast<float>(k * 4), WINDOW_HEIGHT - columns[k].getSize().y);
                columns[k].setFillColor(gradientColor(k));
                columns[k].setOutlineColor(sf::Color::Black); // Đặt màu viền đen cho cột
                columns[k].setOutlineThickness(1);

                window.draw(columns[k]);
            }

            // Hiển thị task vụ bên trái với kích thước font 18
            sf::Text algorithmName("Algorithm: Insertion Sort", font, 18);
            sf::Text arraySize("Number of elements: " + std::to_string(ARRAY_SIZE), font, 18);
            sf::Text sortedRatio("Sorted ratio: " + std::to_string(static_cast<double>(swaps) / (ARRAY_SIZE - 1)), font, 18);
            sf::Text comparisonsText("Comparisons performed: " + std::to_string(comparisons), font, 18);
            sf::Text swapsText("Swaps performed: " + std::to_string(swaps), font, 18);

            algorithmName.setPosition(10, 10);
            arraySize.setPosition(10, 40);
            sortedRatio.setPosition(10, 70);
            comparisonsText.setPosition(10, 100);
            swapsText.setPosition(10, 130);

            window.draw(algorithmName);
            window.draw(arraySize);
            window.draw(sortedRatio);
            window.draw(comparisonsText);
            window.draw(swapsText);

            window.display();

            sf::sleep(sf::seconds(FRAME_DELAY));

            j--;
        }

        arr[j + 1] = key;
    }

    for (int k = 0; k < n; k++) {
        swapSound.play();
        window.clear();

        for (int k = 0; k < ARRAY_SIZE; k++) {
            columns[k].setPosition(static_cast<float>(k * 4), WINDOW_HEIGHT - columns[k].getSize().y);
            columns[k].setFillColor(gradientColor(k));
            columns[k].setOutlineColor(sf::Color::Black); // Đặt màu viền đen cho cột
            columns[k].setOutlineThickness(1);

            window.draw(columns[k]);
        }

        columns[k].setPosition(static_cast<float>(k * 4), WINDOW_HEIGHT - columns[k].getSize().y);
        columns[k].setFillColor(sf::Color::White);
        columns[k].setOutlineColor(sf::Color::Black); // Đặt màu viền đen cho cột
        columns[k].setOutlineThickness(1);
        window.draw(columns[k]);

        sf::sleep(sf::seconds(0.001f));

        // Hiển thị task vụ bên trái với kích thước font 18
        sf::Text algorithmName("Algorithm: Insertion Sort", font, 18);
        sf::Text arraySize("Number of elements: " + std::to_string(ARRAY_SIZE), font, 18);
        sf::Text sortedRatio("Sorted ratio: " + std::to_string(static_cast<double>(swaps) / (ARRAY_SIZE - 1)), font, 18);
        sf::Text comparisonsText("Comparisons performed: " + std::to_string(comparisons), font, 18);
        sf::Text swapsText("Swaps performed: " + std::to_string(swaps), font, 18);

        algorithmName.setPosition(10, 10);
        arraySize.setPosition(10, 40);
        sortedRatio.setPosition(10, 70);
        comparisonsText.setPosition(10, 100);
        swapsText.setPosition(10, 130);

        window.draw(algorithmName);
        window.draw(arraySize);
        window.draw(sortedRatio);
        window.draw(comparisonsText);
        window.draw(swapsText);

        window.display();

        sf::sleep(sf::seconds(0.01f));
    }
}

void selectionSort(std::vector<std::pair<int, int>>& temp, std::vector<sf::RectangleShape>& columns, std::vector<ColumnColor>& columnColors, sf::Sound& swapSound, sf::RenderWindow& window, sf::Font& font) {
    int n = temp.size();
    int comparisons = 0;
    int swaps = 0;
    std::vector<int> arr;
    for (auto& it : temp) arr.push_back(it.first);

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
        std::swap(columns[i], columns[minIndex]);
        std::swap(columnColors[i], columnColors[minIndex]); // Sắp xếp mảng màu tương ứng
        swaps++;
        swapSound.play();

        window.clear();

        for (int k = 0; k < ARRAY_SIZE; k++) {
            columns[k].setPosition(static_cast<float>(k * 4), WINDOW_HEIGHT - columns[k].getSize().y);
            columns[k].setFillColor(gradientColor(k));
            columns[k].setOutlineColor(sf::Color::Black); // Đặt màu viền đen cho cột
            columns[k].setOutlineThickness(1);

            window.draw(columns[k]);
        }

        // Hiển thị task vụ bên trái với kích thước font 18
        sf::Text algorithmName("Algorithm: Selection Sort", font, 18);
        sf::Text arraySize("Number of elements: " + std::to_string(ARRAY_SIZE), font, 18);
        sf::Text sortedRatio("Sorted ratio: " + std::to_string(static_cast<double>(swaps) / (ARRAY_SIZE - 1)), font, 18);
        sf::Text comparisonsText("Comparisons performed: " + std::to_string(comparisons), font, 18);
        sf::Text swapsText("Swaps performed: " + std::to_string(swaps), font, 18);

        algorithmName.setPosition(10, 10);
        arraySize.setPosition(10, 40);
        sortedRatio.setPosition(10, 70);
        comparisonsText.setPosition(10, 100);
        swapsText.setPosition(10, 130);

        window.draw(algorithmName);
        window.draw(arraySize);
        window.draw(sortedRatio);
        window.draw(comparisonsText);
        window.draw(swapsText);

        window.display();

        sf::sleep(sf::seconds(0.05f));
    }
    for (int k = 0; k < n; k++) {
        swapSound.play();
        window.clear();

        for (int k = 0; k < ARRAY_SIZE; k++) {
            columns[k].setPosition(static_cast<float>(k * 4), WINDOW_HEIGHT - columns[k].getSize().y);
            columns[k].setFillColor(gradientColor(k));
            columns[k].setOutlineColor(sf::Color::Black); // Đặt màu viền đen cho cột
            columns[k].setOutlineThickness(1);

            window.draw(columns[k]);
        }

        columns[k].setPosition(static_cast<float>(k * 4), WINDOW_HEIGHT - columns[k].getSize().y);
        columns[k].setFillColor(sf::Color::White);
        columns[k].setOutlineColor(sf::Color::Black); // Đặt màu viền đen cho cột
        columns[k].setOutlineThickness(1);
        window.draw(columns[k]);

        sf::sleep(sf::seconds(0.001f));

        // Hiển thị task vụ bên trái với kích thước font 18
        sf::Text algorithmName("Algorithm: Selection Sort", font, 18);
        sf::Text arraySize("Number of elements: " + std::to_string(ARRAY_SIZE), font, 18);
        sf::Text sortedRatio("Sorted ratio: " + std::to_string(static_cast<double>(swaps) / (ARRAY_SIZE - 1)), font, 18);
        sf::Text comparisonsText("Comparisons performed: " + std::to_string(comparisons), font, 18);
        sf::Text swapsText("Swaps performed: " + std::to_string(swaps), font, 18);

        algorithmName.setPosition(10, 10);
        arraySize.setPosition(10, 40);
        sortedRatio.setPosition(10, 70);
        comparisonsText.setPosition(10, 100);
        swapsText.setPosition(10, 130);

        window.draw(algorithmName);
        window.draw(arraySize);
        window.draw(sortedRatio);
        window.draw(comparisonsText);
        window.draw(swapsText);

        window.display();

        sf::sleep(sf::seconds(0.01f));
    }
}

void shakerSort(std::vector<std::pair<int, int>>& temp, std::vector<sf::RectangleShape>& columns, std::vector<ColumnColor>& columnColors, sf::Sound& swapSound, sf::RenderWindow& window, sf::Font& font) {
    int n = temp.size();
    int comparisons = 0;
    int swaps = 0;
    std::vector<int> arr;
    for (auto& it : temp) arr.push_back(it.first);

    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            comparisons++;
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                std::swap(columns[i], columns[i + 1]);
                std::swap(columnColors[i], columnColors[i + 1]); // Sắp xếp mảng màu tương ứng
                swaps++;
                swapSound.play();
                swapped = true;

                window.clear();

                for (int k = 0; k < ARRAY_SIZE; k++) {
                    columns[k].setPosition(static_cast<float>(k * 4), WINDOW_HEIGHT - columns[k].getSize().y);
                    columns[k].setFillColor(gradientColor(k));
                    columns[k].setOutlineColor(sf::Color::Black); // Đặt màu viền đen cho cột
                    columns[k].setOutlineThickness(1);

                    window.draw(columns[k]);
                }

                // Hiển thị task vụ bên trái với kích thước font 18
                sf::Text algorithmName("Algorithm: Shaker Sort", font, 18);
                sf::Text arraySize("Number of elements: " + std::to_string(ARRAY_SIZE), font, 18);
                sf::Text sortedRatio("Sorted ratio: " + std::to_string(static_cast<double>(swaps) / (ARRAY_SIZE - 1)), font, 18);
                sf::Text comparisonsText("Comparisons performed: " + std::to_string(comparisons), font, 18);
                sf::Text swapsText("Swaps performed: " + std::to_string(swaps), font, 18);

                algorithmName.setPosition(10, 10);
                arraySize.setPosition(10, 40);
                sortedRatio.setPosition(10, 70);
                comparisonsText.setPosition(10, 100);
                swapsText.setPosition(10, 130);

                window.draw(algorithmName);
                window.draw(arraySize);
                window.draw(sortedRatio);
                window.draw(comparisonsText);
                window.draw(swapsText);

                window.display();

                sf::sleep(sf::seconds(FRAME_DELAY));
            }
        }

        if (!swapped) break;

        swapped = false;
        for (int i = n - 2; i >= 0; i--) {
            comparisons++;
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                std::swap(columns[i], columns[i + 1]);
                std::swap(columnColors[i], columnColors[i + 1]); // Sắp xếp mảng màu tương ứng
                swaps++;
                swapSound.play();
                swapped = true;

                window.clear();

                for (int k = 0; k < ARRAY_SIZE; k++) {
                    columns[k].setPosition(static_cast<float>(k * 4), WINDOW_HEIGHT - columns[k].getSize().y);
                    columns[k].setFillColor(gradientColor(k));
                    columns[k].setOutlineColor(sf::Color::Black); // Đặt màu viền đen cho cột
                    columns[k].setOutlineThickness(1);

                    window.draw(columns[k]);
                }

                // Hiển thị task vụ bên trái với kích thước font 18
                sf::Text algorithmName("Algorithm: Shaker Sort", font, 18);
                sf::Text arraySize("Number of elements: " + std::to_string(ARRAY_SIZE), font, 18);
                sf::Text sortedRatio("Sorted ratio: " + std::to_string(static_cast<double>(swaps) / (ARRAY_SIZE - 1)), font, 18);
                sf::Text comparisonsText("Comparisons performed: " + std::to_string(comparisons), font, 18);
                sf::Text swapsText("Swaps performed: " + std::to_string(swaps), font, 18);

                algorithmName.setPosition(10, 10);
                arraySize.setPosition(10, 40);
                sortedRatio.setPosition(10, 70);
                comparisonsText.setPosition(10, 100);
                swapsText.setPosition(10, 130);

                window.draw(algorithmName);
                window.draw(arraySize);
                window.draw(sortedRatio);
                window.draw(comparisonsText);
                window.draw(swapsText);

                window.display();

                sf::sleep(sf::seconds(FRAME_DELAY));
            }
        }
    } while (swapped);
}

// Hàm sắp xếp Quick Sort
void quickSort(std::vector<std::pair<int, int>>& temp, std::vector<sf::RectangleShape>& columns, std::vector<ColumnColor>& columnColors, sf::Sound& swapSound, sf::RenderWindow& window, sf::Font& font, int low, int high) {
    if (low < high) {
        int pivot = temp[high].first;

        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (temp[j].first < pivot) {
                i++;
                std::swap(temp[i], temp[j]);
                std::swap(columns[i], columns[j]);
                std::swap(columnColors[i], columnColors[j]);
                swapSound.play();

                window.clear();

                for (int k = 0; k < ARRAY_SIZE; k++) {
                    columns[k].setPosition(static_cast<float>(k * 4), WINDOW_HEIGHT - columns[k].getSize().y);
                    columns[k].setFillColor(gradientColor(k));
                    columns[k].setOutlineColor(sf::Color::Black); // Đặt màu viền đen cho cột
                    columns[k].setOutlineThickness(1);

                    window.draw(columns[k]);
                }

                // Hiển thị task vụ bên trái với kích thước font 18
                sf::Text algorithmName("Algorithm: Quick Sort (Recursive)", font, 18);
                sf::Text arraySize("Number of elements: " + std::to_string(ARRAY_SIZE), font, 18);
                sf::Text comparisonsText("Comparisons performed: " + std::to_string(high - low), font, 18);

                algorithmName.setPosition(10, 10);
                arraySize.setPosition(10, 40);
                comparisonsText.setPosition(10, 70);

                window.draw(algorithmName);
                window.draw(arraySize);
                window.draw(comparisonsText);

                window.display();

                sf::sleep(sf::seconds(FRAME_DELAY));
            }
        }

        std::swap(temp[i + 1], temp[high]);
        std::swap(columns[i + 1], columns[high]);
        std::swap(columnColors[i + 1], columnColors[high]);
        swapSound.play();

        window.clear();

        for (int k = 0; k < ARRAY_SIZE; k++) {
            columns[k].setPosition(static_cast<float>(k * 4), WINDOW_HEIGHT - columns[k].getSize().y);
            columns[k].setFillColor(gradientColor(k));
            columns[k].setOutlineColor(sf::Color::Black); // Đặt màu viền đen cho cột
            columns[k].setOutlineThickness(1);

            window.draw(columns[k]);
        }

        // Hiển thị task vụ bên trái với kích thước font 18
        sf::Text algorithmName("Algorithm: Quick Sort (Recursive)", font, 18);
        sf::Text arraySize("Number of elements: " + std::to_string(ARRAY_SIZE), font, 18);
        sf::Text comparisonsText("Comparisons performed: " + std::to_string(high - low), font, 18);

        algorithmName.setPosition(10, 10);
        arraySize.setPosition(10, 40);
        comparisonsText.setPosition(10, 70);

        window.draw(algorithmName);
        window.draw(arraySize);
        window.draw(comparisonsText);

        window.display();

        sf::sleep(sf::seconds(0.05f));

        int pi = i + 1;

        quickSort(temp, columns, columnColors, swapSound, window, font, low, pi - 1);
        quickSort(temp, columns, columnColors, swapSound, window, font, pi + 1, high);
    }
}

// Hàm visualizeSort chính
void visualizeSort(const std::string& sortType) {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), sortType + " Sort Visualization");
    std::vector<std::pair<int, int>> numbers;
    std::vector<sf::RectangleShape> columns(ARRAY_SIZE);
    std::vector<ColumnColor> columnColors(ARRAY_SIZE);

    int infront = 1;
    for (int i = 1; i <= ARRAY_SIZE; i++) {
        infront += 5;
        numbers.push_back({ infront, i / (ARRAY_SIZE / 8) });
    }

    // Trộn mảng ngẫu nhiên
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(numbers.begin(), numbers.end(), g);

    // Tạo mảng cột với gradient màu cho các cột ban đầu
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sf::RectangleShape bar(sf::Vector2f(4.0f, static_cast<float>(numbers[i].first / 2)));
        columns[i] = bar;
    }

    sf::SoundBuffer swapBuffer;
    swapBuffer.loadFromFile("ticktack.wav");
    sf::Sound swapSound;
    swapSound.setBuffer(swapBuffer);

    int firstCompareIndex = -1;
    int secondCompareIndex = -1;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Font not found!" << std::endl;
        return;
    }

        window.clear();

        if (sortType == "Insertion") {
            insertionSort(numbers, columns, columnColors, swapSound, window, font);
        }
        else if (sortType == "Selection") {
            selectionSort(numbers, columns, columnColors, swapSound, window, font);
        }
        else if (sortType == "Bubble") {
            bubbleSort(numbers, columns, columnColors, swapSound, window, font);
        }
        else if (sortType == "Shaker") {
            shakerSort(numbers, columns, columnColors, swapSound, window, font);
        }
        else if (sortType == "Quick") {
            quickSort(numbers, columns, columnColors, swapSound, window, font, 0, ARRAY_SIZE - 1);
        }

}

int main() {

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sort Visualization");
    sf::SoundBuffer swapBuffer;
    swapBuffer.loadFromFile("ticktack.wav");
    sf::Sound swapSound;
    swapSound.setBuffer(swapBuffer);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        visualizeSort("Selection");
        swapSound.play();
        sf::sleep(sf::seconds(0.0f));

        visualizeSort("Insertion");
        swapSound.play();
        sf::sleep(sf::seconds(0.0f));

        visualizeSort("Bubble");
        swapSound.play();
        sf::sleep(sf::seconds(0.0f));

        visualizeSort("Shaker");
        swapSound.play();
        sf::sleep(sf::seconds(0.0f));

        visualizeSort("Quick");
        swapSound.play();
        sf::sleep(sf::seconds(0.0f));

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
        }
    }
    return 0;
}
