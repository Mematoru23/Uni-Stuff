package Service;

import Domain.Cake;
import Domain.Order;
import Repo.DuplicateEntityException;
import Repo.IRepo;

import java.io.IOException;
import java.util.Collection;
import java.util.List;

public class OrderService {
    IRepo<Order> repository;

    public OrderService(IRepo<Order> repository) {
        this.repository = repository;
    }

    public void addOrder(int id, List<Cake> lc, String date) throws DuplicateEntityException, IOException {
        repository.add(new Order(id, lc, date));
    }

    public void removeOrder(int id) throws Exception {
        repository.remove(id);
    }

    public void modifyOrder(int id, List<Cake> cakes, String date) throws Exception
    {
        repository.modify(new Order(id, cakes, date));
    }

    public Order findById(int id)
    {
        return repository.findById(id);
    }

    public Collection<Order> getAll()
    {
        return repository.getAll();
    }
}
