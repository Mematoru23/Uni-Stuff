import Domain.*;
import Repo.*;
import Service.CakeService;
import Service.OrderService;
import UI.Console;
import UnitTest.UnitTest;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.Map;
import java.util.Objects;
import java.util.Properties;

public class Main {
    public static void main(String[] args) throws Exception {
        try {
            UnitTest test = new UnitTest();
            test.runTests();
            System.out.println("All tests passed!");
        } catch (AssertionError | IOException e) {
            System.err.println("Some tests failed: " + e.getMessage());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

        FileRepo cakeRepo = CakeFileRepo();
        FileRepo order = OrderFileRepo();
        CakeService cakeService = new CakeService(cakeRepo);
        OrderService orderService = new OrderService(order);
        Console ui = new Console(cakeService, orderService);
        ui.runMenu();
    }

    private static FileRepo CakeFileRepo() throws DuplicateEntityException, FileNotFoundException {
        IEntityFactory<Cake> cakeFactory = new CakeFactory();
        Properties properties = new Properties();
        try(InputStream is = new FileInputStream("src/settings.properties")) {
            properties.load(is);
            if (properties.getProperty("Repo").equals("text"))
                return new FileRepo("cakes.txt", cakeFactory);

            if (properties.getProperty("Repo").equals("bin"))
                return new FileRepo("cakes.bin", cakeFactory);

        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        return new FileRepo("cakes.txt", cakeFactory);
    }

    private static FileRepo OrderFileRepo() throws DuplicateEntityException, FileNotFoundException {
        IEntityFactory<Order> orderFactory = new OrderFactory();
        Properties properties = new Properties();
        try(InputStream is = new FileInputStream("src/settings.properties")) {
            properties.load(is);
            if (properties.getProperty("Repo").equals("text"))
                return new FileRepo("orders.txt", orderFactory);

            if (properties.getProperty("Repo").equals("bin"))
                return new FileRepo("orders.bin", orderFactory);

        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        return new FileRepo("orders.txt", orderFactory);
    }
}
