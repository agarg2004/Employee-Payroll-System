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

## DEMO

<img width="1561" height="790" alt="Screenshot 2025-09-27 163824" src="https://github.com/user-attachments/assets/857096ed-2aea-4dde-a05a-94e7a0d4bac5" /><img width="1153" height="715" alt="Screenshot 2025-09-27 163831" src="https://github.com/user-attachments/assets/a79624d0-d9ee-4804-b752-9b53a76bda39" />
<img width="1062" height="641" alt="Screenshot 2025-09-27 164003" src="https://github.com/user-attachments/assets/ce091944-29be-4ff4-aa59-0fd1f9cc4066" />
<img width="1087" height="592" alt="Screenshot 2025-09-27 164012" src="https://github.com/user-attachments/assets/e10195c9-a548-43ca-bf8d-66807b72869d" />
<img width="1058" height="559" alt="Screenshot 2025-09-27 164023" src="https://github.com/user-attachments/assets/d1d068e1-3a2c-41a6-a224-15a0e537c3fd" />
<img width="1013" height="590" alt="Screenshot 2025-09-27 164035" src="https://github.com/user-attachments/assets/a57333c5-76fb-4b2e-8df6-c81d026d9686" />
<img width="662" height="404" alt="Screenshot 2025-09-27 164058" src="https://github.com/user-attachments/assets/7e730ca9-2a20-4b84-8c7a-18221e4a7d3e" />

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
