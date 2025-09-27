# 🏢 Employee Payroll Management System

A **C++ & MySQL-based Employee Payroll Management System** designed to simplify employee salary management, track loans, allowances, and automate payroll calculations efficiently.

---

## ✨ Features

* **Add / Insert Employee Records**
  Add new employees with complete details such as name, code, designation, experience, age, and working hours.

* **Automatic Salary Computation**
  Calculates salary components including:

  * Basic Salary
  * DA (Dearness Allowance)
  * HRA (House Rent Allowance)
  * PF (Provident Fund)
  * Tax
  * Meal, Medical, Transport Allowances
  * Loan deduction if applicable

* **Update Employee Records**
  Modify existing employee data and automatically update salary computations.

* **Save to Database**
  Integrates with **MySQL** to persist employee records using `INSERT` and `ON DUPLICATE KEY UPDATE`.

* **Input Validation**
  Ensures clean and valid employee data entry.

* **Interactive Console UI**
  Simple and user-friendly interface using console positioning functions (`gotoXY`) and menus.

---

## 💻 Technologies Used

* **C++** – Core language for console application logic
* **MySQL** – Database for storing employee records
* **Dev-C++** – Development environment
* **SQL Queries** – For CRUD operations on employee database

---

## 🛠 Installation

1. Clone the repository:

```bash
git clone https://github.com/your-username/employee-payroll-system.git
```

2. Open in **Dev-C++** or your preferred IDE.

3. Make sure **MySQL Server** is installed and running.

4. Update database connection parameters in your code:

```cpp
// Example
db.connect("localhost", "root", "password", "payrolldb");
```

5. Compile and run the project.

---

## 📝 Usage

1. Run the executable `employee payroll.exe`.
2. Use menu options to:

   * Insert new employee records
   * Update or edit records
   * Save all records to the database
   * View employee salary details

---

## 📊 Salary Calculation Logic

* **Salary** = Working Hours × Rate per Hour (default 300)
* **DA** = 1.20 × Salary
* **PF** = 12% of Salary
* **HRA** = 27% of Salary
* **Tax** = 4% of Salary
* **Loan Debit** = 9% of Salary (if applicable)
* **Gross Pay** = Salary + Allowances - Deductions

---

## ⚡ Future Improvements

* GUI-based interface for better user experience
* Export payroll reports to Excel/PDF
* Support for multiple currencies and tax brackets
* Role-based access control for admin and HR staff

---

## 🧑‍💻 Author

**Anirudh Garg** – [GitHub](https://github.com/anirudhgarg) | [LinkedIn](https://linkedin.com/in/anirudhgarg)

---

## 📜 License

This project is **MIT Licensed** – feel free to use, modify, and distribute.

---
