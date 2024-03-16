package UnitTest;

import Domain.Entity;
import Domain.Cake;
import Domain.Order;
import Repo.DuplicateEntityException;
import Repo.MemRepo;
import Service.CakeService;
import Service.OrderService;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class UnitTest {

    private MemRepo<Cake> cakeRepo = new MemRepo<>();
    private MemRepo<Order> orderRepo = new MemRepo<>();
    private CakeService cakeService = new CakeService(cakeRepo);
    private OrderService orderService = new OrderService(orderRepo);
    private Cake cake1 = new Cake(1, "cake1");
    private Cake cake2 = new Cake(2, "cake22");
    private List<Cake> cakeList = new ArrayList<Cake>();

    public UnitTest() throws IOException, DuplicateEntityException {
        this.cakeService.addCake(1, "cake1");
        this.cakeService.addCake(2, "cake22");
        cakeList.add(cake1);
        cakeList.add(cake2);

        Order order1 = new Order(1, cakeList, "22/12/2023");
        this.orderService.addOrder(1, cakeList, "22/12/2023");
    }

    public void runTests() throws Exception {
        testAdd();
        testModify();
        testRemove();
    }

    private void assertEquals(Object expected, Object actual) {
        if (!expected.equals(actual)) {
            throw new AssertionError("Expected: " + expected + ", but was: " + actual);
        }
    }

    private void assertTrue(boolean condition) {
        if (!condition) {
            throw new AssertionError("Expected: true, but was: false");
        }
    }

    private void testAdd() {
        assertEquals(2, cakeService.getAll().size());
        assertEquals(1, orderService.getAll().size());
        assertTrue(cakeService.getAll().size() == 2);
    }

    private void testModify() throws Exception {
        cakeService.modifyCake(2, "aaa");
        orderService.modifyOrder(1, cakeList, "01/01/2023");
        List<Cake> cakeListMod = (ArrayList<Cake>) cakeService.getAll();
        List<Order> orderListMod = (ArrayList<Order>) orderService.getAll();
        assertEquals("cake1", cakeListMod.get(0).getCakeType());
        assertEquals("aaa", cakeListMod.get(1).getCakeType());
        assertEquals("01/01/2023", orderListMod.get(0).getDate());
    }

    private void testRemove() throws Exception {
        cakeService.removeCake(1);
        orderService.removeOrder(1);
        List<Cake> cakeList = (ArrayList<Cake>) cakeService.getAll();
        List<Order> orderList = (ArrayList<Order>) orderService.getAll();
        assertEquals(1, cakeList.size());
        assertEquals(0, orderList.size());
    }

    public static void main(String[] args) throws Exception {
        UnitTest test = new UnitTest();
        test.runTests();
        System.out.println("All tests passed!");
    }
}
