double calculateDiscount(double price, double discountPercent);

double calculatePrice(double initialPrice, double firstDiscountBorder, double secondDiscountBorder,
                      double firstDiscountPercent, double secondDiscountPercent) {
    if (initialPrice < firstDiscountBorder) {
        return initialPrice;
    }

    if (initialPrice > secondDiscountBorder) {
        return calculateDiscount(initialPrice, secondDiscountPercent);
    }

    return calculateDiscount(initialPrice, firstDiscountPercent);
}

double calculateDiscount(double price, double discountPercent) {
    double discountValue = (price / 100) * discountPercent;
    return price - discountValue;
}
