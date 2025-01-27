shopping_cart = []
product_names = ["Pen", "Pencil", "Eraser", "Pencil Box", "Sharpener", "Compass", "Divider", "Small Scale", "Large Scale"]

choice = 0
while True:
    print("\nSlect your choice:")
    print("1. View Available Products")
    print("2. View your cart")
    print("3. Add products to your cart")
    print("4. Delete products from your cart")
    print("5. Exit")
    choice = int(input("Enter your choice:"))

    if choice == 1:
        print("")
        for i in range(len(product_names)):
            print(f"{i + 1}. {product_names[i]}", end ="  ")
        print("")

    elif choice == 2:
        print("")
        if len(shopping_cart) != 0:
            for i in range(len(shopping_cart)):
                print(f"{i + 1}. {shopping_cart[i]}", end ="  ")
        else:
            print("Your Cart is Empty...")
        print("")
    
    elif choice == 3:
        print("")
        i = 0
        for i in range(len(product_names)):
            print(f"{i + 1}. {product_names[i]}", end ="  ")
        pid = int(input("Enter the index of product from above to add to your cart:"))
        shopping_cart.append(product_names[pid - 1])
        print("Product added to your cart...")
    
    elif choice == 4:
        print("")
        i = 0
        for i in range(len(shopping_cart)):
            print(f"{i + 1}. {shopping_cart[i]}", end ="  ")
        pid = int(input("Enter the index of product from above to delete from your cart:"))
        shopping_cart.remove(shopping_cart[pid - 1])
        print("Product removed from your cart...")

    elif choice == 5:
        print("Exiting...")
        break

    else:
        print("Enter a valid choice!")