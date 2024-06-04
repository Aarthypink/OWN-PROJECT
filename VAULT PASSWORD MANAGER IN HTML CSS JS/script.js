// script.js
let passwords = [];

function addPassword() {
    const site = document.getElementById('site').value;
    const username = document.getElementById('username').value;
    const password = document.getElementById('password').value;
    const category = document.getElementById('category').value;
    if (site && username && password && category) {
        passwords.push({ site, username, password, category });
        document.getElementById('site').value = '';
        document.getElementById('username').value = '';
        document.getElementById('password').value = '';
        document.getElementById('category').value = '';
        renderPasswords();
    } else {
        alert('Please enter website, username, password and category');
    }
}

function searchPassword() {
    const searchQuery = document.getElementById('search').value.toLowerCase();
    const filteredPasswords = passwords.filter(password => 
        password.site.toLowerCase().includes(searchQuery)
    );
    renderPasswords(filteredPasswords);
}

function renderPasswords(filteredPasswords = passwords) {
    const passwordList = document.getElementById('passwordList');
    passwordList.innerHTML = '';

    filteredPasswords.forEach((password, index) => {
        const li = document.createElement('li');
        li.className = 'password-item';
        li.innerHTML = `
            CATEGORY: ${password.category}<br>
LINK: ${password.site} <br> USERNAME: ${password.username}<br> 
            <button onclick="deletePassword(${index})">Delete</button>
            <button onclick="editPassword(${index})">Edit</button>
        `;
        passwordList.appendChild(li);
    });
}

function deletePassword(index) {
    passwords.splice(index, 1);
    renderPasswords();
}

function editPassword(index) {
    const newSite = prompt('Enter new website:', passwords[index].site);
    const newUsername = prompt('Enter new username:', passwords[index].username);
    const newPassword = prompt('Enter new password:', passwords[index].password);
    const newCategory = prompt('Enter new category:', passwords[index].category);


    if (newSite && newUsername && newPassword) {
        passwords[index] = { site: newSite, username: newUsername, password: newPassword , category: newCategory };
        renderPasswords();
    } else {
        alert('Please enter website, username, password and category');
    }
}

// Initial render
renderPasswords();