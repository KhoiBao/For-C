#include <stdio.h>

struct Phanso {
    int tu;
    int mau;
};

void nhap(struct Phanso *ps) {
    printf("\nNhap vao tu so: ");
    scanf("%d", &ps->tu);

    do {
        printf("Nhap vao mau so (>0): ");
        scanf("%d", &ps->mau);
    } while (ps->mau == 0);
    if (ps->mau < 0) {
        ps->tu *= -1;
        ps->mau *= -1;
    }
}

void xuat(struct Phanso ps) {
    printf("\t%d/%d", ps.tu, ps.mau);
}

void sosanh(struct Phanso ps) {
    if (ps.tu / ps.mau > 1) {
        printf("\nPhan so lon hon 1");
    } else if ((float)ps.tu / ps.mau == 1) {
        printf("\nPhan so bang 1");
    } else {
        printf("\nPhan so nho hon 1");
    }
}

int ucln(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void toigian(struct Phanso *ps) {
    int n = ucln(ps->tu, ps->mau);
    ps->tu /= n;
    ps->mau /= n;
}

struct Phanso congphanso(struct Phanso ps1, struct Phanso ps2) {
    struct Phanso ketqua;
    ketqua.tu = (ps1.tu * ps2.mau) + (ps2.tu * ps1.mau);
    ketqua.mau = ps1.mau * ps2.mau;
    return ketqua;
}

struct Phanso hieuphanso(struct Phanso ps1, struct Phanso ps2) {
    struct Phanso ketqua;
    ketqua.tu = (ps1.tu * ps2.mau) - (ps2.tu * ps1.mau);
    ketqua.mau = ps1.mau * ps2.mau;
    return ketqua;
}
struct Phanso nhanphanso(struct Phanso ps1, struct Phanso ps2) {
    struct Phanso ketqua;
    ketqua.tu = ps1.tu * ps2.tu ;
    ketqua.mau = ps1.mau * ps2.mau;
    return ketqua;
}
struct Phanso chiaphanso(struct Phanso ps1, struct Phanso ps2) {
    struct Phanso ketqua;
    ketqua.tu = ps1.tu * ps2.mau ;
    ketqua.mau = ps1.mau * ps2.tu;
    return ketqua;
}

int main() {
    struct Phanso ps1, ps2;

    printf("\nNhap phan so thu nhat: ");
    nhap(&ps1);

    printf("\nNhap phan so thu hai: ");
    nhap(&ps2);

    printf("\nPhan so vua nhap la: ");
    xuat(ps1);
    xuat(ps2);

    printf("\nPhan so thu nhat: ");
    sosanh(ps1);

    printf("\nPhan so thu hai: ");
    sosanh(ps2);

    toigian(&ps1);
    toigian(&ps2);

    printf("\nPhan so sau khi rut gon la: %d/%d", ps1.tu, ps1.mau);
    printf("\nPhan so sau khi rut gon la: %d/%d", ps2.tu, ps2.mau);

    struct Phanso tong = congphanso(ps1, ps2);
    printf("\nCong 2 phan so: ");
    xuat(tong);

    struct Phanso hieu = hieuphanso(ps1, ps2);
    printf("\nHieu 2 phan so: ");
    xuat(hieu);

    struct Phanso tich = nhanphanso(ps1, ps2);
    printf("\nTich 2 phan so: ");
    xuat(tich);

    struct Phanso thuong = chiaphanso(ps1, ps2);
    printf("\nChia 2 phan so: ");
    xuat(thuong);
    return 0;
}
