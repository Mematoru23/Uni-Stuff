import src.Domain.*;
import src.Repo.DuplicateEntityException;
import src.Repo.FileRepo;
import src.Repo.IRepo;
import src.Repo.MemRepo;
import src.Service.CakeService;
import src.Service.OrderService;
import src.UI.Console;

import java.io.FileNotFoundException;

public class Main {
    public static void main(String[] args) throws DuplicateEntityException, FileNotFoundException {
        //IRepo<Cake> cakeRepo = new MemRepo<>();
        IEntityFactory<Cake> cakeFactory = new CakeFactory();
        IEntityFactory<Order> orderFactory = new OrderFactory();

        IRepo<Cake> cakeRepo = new FileRepo<>("cakes.txt", cakeFactory);
        IRepo<Order> orderRepo = new FileRepo<>("orders.txt", orderFactory);

        CakeService cakeService = new CakeService(cakeRepo);
        OrderService orderService = new OrderService(orderRepo);

        Console console = new Console(cakeService, orderService);

        console.runMenu();
    }
}
