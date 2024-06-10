#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// 定义客房类
class Room {
public:
    int roomNumber;
    std::string status; // 房间状态：空或已占用
    std::string guestName; // 入住客人的名字

    Room(int number) : roomNumber(number), status("空"), guestName("") {}
};

// 定义宾馆类
class Hotel {
private:

    std::string roomFile;
    std::string guestFile;

public:
    std::vector<Room> rooms;
    Hotel(const std::string& roomFile, const std::string& guestFile)
            : roomFile(roomFile), guestFile(guestFile) {
        loadRooms();
    }

    void loadRooms() {
        std::ifstream file(roomFile);
        int number;
        while (file >> number) {
            rooms.push_back(Room(number));
        }
        file.close();
    }

    void saveRooms() {
        std::ofstream file(roomFile);
        for (const auto& room : rooms) {
            file << room.roomNumber << std::endl;
        }
        file.close();
    }

    void addRoom(int number) {
        rooms.push_back(Room(number));
    }

    void checkIn(int roomNumber, const std::string& guestName) {
        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber && room.status == "空") {
                room.status = "已占用";
                room.guestName = guestName;
                saveGuest(guestName, roomNumber);
                break;
            }
        }
        saveRooms();
    }

    void checkOut(int roomNumber) {
        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber) {
                room.status = "空";
                room.guestName = "";
                break;
            }
        }
        saveRooms();
    }

    void saveGuest(const std::string& guestName, int roomNumber) {
        std::ofstream file(guestFile, std::ios::app);//open file in append mode;
        file << guestName << " 入住房间号: " << roomNumber << std::endl;
        file.close();
    }

    void browseRooms() {
        for (const auto& room : rooms) {
            std::cout << "房间号: " << room.roomNumber
                      << ", 状态: " << room.status
                      << ", 客人: " << room.guestName << std::endl;
        }
    }

    Room* findRoom(int number) {
        for (auto& room : rooms) {
            if (room.roomNumber == number) {
                return &room;
            }
        }
        return nullptr;
    }
};

int main() {
    Hotel hotel("rooms.txt", "guests.txt");

    char choice;
    int roomNumber;
    std::string guestName;

    do {
        std::cout << "\n宾馆房间管理系统\n";
        std::cout << "1. 添加房间\n";
        std::cout << "2. 客人入住\n";
        std::cout << "3. 客人退房\n";
        std::cout << "4. 浏览房间信息\n";
        std::cout << "5. 查询空房间\n";
        std::cout << "0. 退出\n";
        std::cout << "请输入选择: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                std::cout << "输入房间号: ";
                std::cin >> roomNumber;
                hotel.addRoom(roomNumber);
                break;
            case '2':
                std::cout << "输入房间号: ";
                std::cin >> roomNumber;
                std::cout << "输入客人姓名: ";
                std::cin >> guestName;
                hotel.checkIn(roomNumber, guestName);
                break;
            case '3':
                std::cout << "输入房间号: ";
                std::cin >> roomNumber;
                hotel.checkOut(roomNumber);
                break;
            case '4':
                hotel.browseRooms();
                break;
            case '5':
                std::cout << "空房间列表:" << std::endl;
                for (const auto& room : hotel.rooms) {
                    if (room.status == "空") {
                        std::cout << room.roomNumber << std::endl;
                    }
                }
                break;
            case '0':
                break;
            default:
                std::cout << "无效的输入，请重新输入！" << std::endl;
        }
    } while (choice != '0');

    return 0;
}