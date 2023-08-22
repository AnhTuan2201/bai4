#include <stdio.h>
#include <string.h>

// Enum để biểu diễn loại sản phẩm
enum ProductType {
    CLOTHING,
    SHOES,
    ELECTRONICS
};

// Union để lưu trữ thông tin kích cỡ hoặc trọng lượng sản phẩm
union ProductInfo {
    char size[10];       // Thông tin kích cỡ (quần áo, giày dép)
    float weight;        // Thông tin trọng lượng (điện tử)
};

// Cấu trúc dữ liệu cho sản phẩm
struct Product {
    char name[50];       // Tên sản phẩm
    float price;         // Giá sản phẩm
    enum ProductType type; // Loại sản phẩm
    union ProductInfo info; // Thông tin kích cỡ hoặc trọng lượng
};

int main() {
    int numProducts;
    printf("Nhập số lượng sản phẩm: ");
    scanf("%d", &numProducts);

    // Khai báo mảng chứa thông tin sản phẩm
    struct Product products[numProducts];

    // Nhập thông tin cho từng sản phẩm
    for (int i = 0; i < numProducts; i++) {
        printf("\nNhập thông tin cho sản phẩm %d:\n", i + 1);
        printf("Tên sản phẩm: ");
        scanf("%s", products[i].name);
        printf("Giá sản phẩm: ");
        scanf("%f", &products[i].price);
        printf("Loại sản phẩm (0: Quần áo, 1: Giày dép, 2: Điện tử): ");
        int type;
        scanf("%d", &type);
        products[i].type = type;
        if (type == CLOTHING || type == SHOES) {
            printf("Kích cỡ: ");
            scanf("%s", products[i].info.size);
        } else if (type == ELECTRONICS) {
            printf("Trọng lượng: ");
            scanf("%f", &products[i].info.weight);
        }
    }

    // Tra cứu thông tin sản phẩm qua tên
    char searchName[50];
    printf("\nNhập tên sản phẩm để tra cứu: ");
    scanf("%s", searchName);

    // Tìm kiếm sản phẩm theo tên và hiển thị thông tin
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, searchName) == 0) {
            printf("\nThông tin sản phẩm:\n");
            printf("Tên sản phẩm: %s\n", products[i].name);
            printf("Giá sản phẩm: %.2f\n", products[i].price);

            switch (products[i].type) {
            case 0:
            printf("Loại sản phẩm: Quần áo\n");
            break;
            case 1:
            printf("Loại sản phẩm: Giày dép\n");
            break;
            case 2:
            printf("Loại sản phẩm: Điện tử\n");
            break;
            default:
            }
            
            if (products[i].type == CLOTHING || products[i].type == SHOES) {
                printf("Kích cỡ: %s\n", products[i].info.size);
            } else if (products[i].type == ELECTRONICS) {
                printf("Trọng lượng: %.2f\n", products[i].info.weight);
            }
            break;
        }
    }

    return 0;
}
