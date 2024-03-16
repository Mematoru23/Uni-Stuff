package src.UI;

import src.Domain.Order;
import src.Repo.DuplicateEntityException;
import src.Repo.MemRepo;
import src.Service.CakeService;
import src.Domain.Cake;
import src.Service.OrderService;

import java.util.*;

public class Console {
    CakeService cakeService;
    OrderService orderService;
    Scanner scanner = new Scanner(System.in);

    public Console(CakeService cakeService, OrderService orderService)
    {
        this.cakeService = cakeService;
        this.orderService = orderService;
    }

    private void printMenu()
    {
        System.out.println("1. Add cake");
        System.out.println("2. Add order");
        System.out.println("3. Modify cake");
        System.out.println("4. Modify order");
        System.out.println("5. Remove cake");
        System.out.println("6. Remove order");
        System.out.println("sc. Show cakes");
        System.out.println("so. Show cakes");
        System.out.println("x. Exit");
    }

    private void addCake()
    {
        try
        {
            System.out.println("Give id: ");
            int id = scanner.nextInt();
            System.out.println("Give cake type: ");
            String type = scanner.next();

            cakeService.addCake(id, type);
        }
        catch (DuplicateEntityException ex)
        {
            System.out.println(ex.getMessage());
        }
        catch (Exception ex)
        {
            System.out.println(ex.getMessage());
        }
    }

    private void modCake()
    {
        try
        {
            System.out.println("Give id: ");
            int id = scanner.nextInt();
            System.out.println("Give cake type: ");
            String type = scanner.next();

            cakeService.modifyCake(id, type);
        }
        catch (Exception ex)
        {
            System.out.println(ex.getMessage());
        }
    }

    private void delCake()
    {
        try
        {
            System.out.println("Give id of cake to delete: ");
            int id = scanner.nextInt();

            cakeService.removeCake(id);
        }
        catch (Exception ex)
        {
            System.out.println(ex.getMessage());
        }
    }

    private void addOrder()
    {
        try
        {
            System.out.println("Give id: ");
            int id = scanner.nextInt();
            System.out.println("Available cakes to order: ");
            showCakes();
            System.out.println("How many cakes do you want to order?: ");
            int noCakes = scanner.nextInt();
            List<Cake> cakes = new ArrayList<>();
            Collection<Cake> allCakes = cakeService.getAll();
            while (noCakes > 0)
            {
                System.out.println("Give id: ");
                int idCake = scanner.nextInt();
                System.out.println("Give cake type: ");
                String type = scanner.next();

                cakes.add(new Cake(idCake, type));
                noCakes--;
            }
            System.out.println("Order date: ");
            String date = scanner.next();

            orderService.addOrder(id, cakes, date);
        }
        catch (DuplicateEntityException ex)
        {
            System.out.println(ex.getMessage());
        }
        catch (Exception ex)
        {
            System.out.println(ex.getMessage());
        }
    }

    private void modOrder()
    {
        try
        {
            System.out.println("Give id: ");
            int id = scanner.nextInt();
            System.out.println("Available cakes to order: ");
            showCakes();
            System.out.println("How many cakes from order do you want to modify?: ");
            int noCakes = scanner.nextInt();
            List<Cake> cakes = new ArrayList<>();
            Collection<Cake> allCakes = cakeService.getAll();
            while (noCakes > 0)
            {
                System.out.println("Give id: ");
                int idC = scanner.nextInt();
                System.out.println("Give new cake type: ");
                String type = scanner.next();

                cakeService.modifyCake(idC, type);
                noCakes--;
            }
            System.out.println("New Order date: ");
            String date = scanner.next();

            orderService.modifyCake(id, cakes, date);
        }
        catch (Exception ex)
        {
            System.out.println(ex.getMessage());
        }
    }

    private void delOrder()
    {
        try
        {
            System.out.println("Give id of order to delete: ");
            int id = scanner.nextInt();

            orderService.removeOrder(id);
        }
        catch (Exception ex)
        {
            System.out.println(ex.getMessage());
        }
    }

    private void showCakes()
    {
        Collection<Cake> cakes = cakeService.getAll();
        for (Cake cake : cakes)
        {
            System.out.println(cake);
        }
    }

    private void showOrder()
    {
        Collection<Order> orders = orderService.getAll();
        for (Order order : orders)
        {
            System.out.println(order);
        }
    }

    public void runMenu(){
        while (true)
        {
            printMenu();
            String cmd = scanner.next();
            switch (cmd)
            {
                case "1":
                {
                    addCake();
                    break;
                }
                case "2":
                {
                    addOrder();
                    break;
                }
                case "3":
                {
                    modCake();
                    break;
                }
                case "4":
                {
                    modOrder();
                    break;
                }
                case "5":
                {
                    delCake();
                    break;
                }
                case "6":
                {
                    delOrder();
                    break;
                }
                case "sc":
                {
                    showCakes();
                    break;
                }
                case "so":
                {
                    showOrder();
                    break;
                }
                case "x":
                {
                    return;
                }
                default:
                {
                    System.out.println("Wrong option!");
                }
            }
        }
    }
}
